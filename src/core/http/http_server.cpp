//
// Created by 王聪 on 2020/4/1.
//

#include "http_server.h"
#include "../../util/rwtool.h"
#include "./error.h"
#include "./http_context.h"
#include "./http_response.h"
#include <any>
#include <glog/logging.h>
#include <sys/stat.h>
namespace qg {
int HTTPServer::kMaxFileSize = 100 * 1024 * 1024;

HTTPServer::HTTPServer(Config *config) : server_(new Server(config)) {
  server_->setMessageCallback(std::bind(&HTTPServer::handleMessageCome, this,
                                        std::placeholders::_1,
                                        std::placeholders::_2));
  server_->setConnectionComeCallBack(std::bind(
      &HTTPServer::handleConnectionCome, this, std::placeholders::_1));
  server_->setConnectionCloseCallBack(std::bind(
      &HTTPServer::handleConnectionClose, this, std::placeholders::_1));
  server_->setWriteCompleteCallBack(std::bind(&HTTPServer::handleWriteComplete,
                                              this, std::placeholders::_1,
                                              std::placeholders::_2));
}

void HTTPServer::handleMessageCome(std::shared_ptr<TcpConnection > conn,
                                   buf_t &read_buf) {
  LOG(INFO) << "handleMessageCome";
  auto http_context =
      std::any_cast<std::shared_ptr<HTTPContext>>(conn->context());
  auto request = http_context->getRequest();
  int nparse = http_context->parse(read_buf);
  if (nparse < 0) {
    conn->shutdown();
    return;
  }

  if (request->message_is_end) {
    LOG(INFO) << "body is final";
    // TODO(qinggniq):
    // 构造response，然后清空request。在handleWrite的时候同时来了一个request怎么办。
    // FIXME(qinggniq):
    // 暂时定的是，先弄一个新的http_request,然后swap，然后处理http_request,
    // 这个时候其他的 线程使用这个http_requst的话也不会崩溃。
    // FIXME(qinggni): 但是一个Connection里面的东西处理事件只在一个线程。
    // 初始化的时候可能用read_buf去初始化比较好。。。。
    auto response = std::make_shared<HTTPResponse>();
    // TODO(qinggniq): sendfile的逻辑；
    // 处理sendfile应该放到handleRequest里面去？
    defaultHandleRequest(request, response);
    conn->write(response->toString());
    http_context->reset();
  }
  LOG(INFO) << "????";
}

void HTTPServer::handleWriteComplete(std::shared_ptr<TcpConnection > conn,
                                     buf_t &read_buf) {
  auto http_context =
      std::any_cast<std::shared_ptr<HTTPContext>>(conn->context());
  auto parser = http_context->getParser();
  if (!http_should_keep_alive(parser)) {
    LOG(INFO) << "shutdwon";
    conn->shutdown();
  }
  LOG(INFO) << "Response send success";
}

void HTTPServer::handleConnectionCome(std::shared_ptr<TcpConnection > conn) {
  auto http_context = std::make_shared<HTTPContext>();
  http_context->bindParser(http_context->getParser());
  conn->setContext(std::move(http_context));
  // 这里可能需要记录一下ip限制性？
  // data设置为request，那么http-parser的callback就只能填数据，而不能进行任何IO操作。合理。
  LOG(INFO) << "New HTTP Client Come in";
}

void HTTPServer::handleConnectionClose(std::shared_ptr<TcpConnection > conn) {
  LOG(INFO) << "HTTP Client leave";
}

void HTTPServer::handleRequest(std::shared_ptr<HTTPRequest> &request,
                               std::shared_ptr<HTTPResponse> &response) {
  LOG(INFO) << "deafult HandleRequest";
  router_t::mapped_type real_router;
  // 在这里URL需要把后面的query去掉。
  switch (request->method) {
  case HTTP_GET:
    real_router = router_[Method::GET];
    break;
  case HTTP_DELETE:
    real_router = router_[Method::DELETE];
    break;
  case HTTP_POST:
    real_router = router_[Method::POST];
    break;
  case HTTP_PUT:
    real_router = router_[Method::PUT];
    break;
  default:
    LOG(ERROR) << "un support method " << http_method_str(request->method);
    // 返回一个bad request
    response->setStatus(405);
    return;
  }
  // 可能不是path。
  bool has_route_cb =
      real_router.find(request->request_path) != real_router.end();

  if (has_route_cb) {
    real_router[request->request_path](request, response);
  } else {
    defaultHandleRequest(request, response);
  }
}

void HTTPServer::defaultHandleRequest(std::shared_ptr<HTTPRequest> &request,
                                      std::shared_ptr<HTTPResponse> &response) {
  // FIXME(qinggniq):设置root值。
  qg_string root = ".";
  qg_string file_path = root + request->request_path;
  response->setHeader("FilePath", file_path);
  struct stat st;
  int ret = stat(file_path.c_str(), &st);
  if (ret < 0) {
    LOG(INFO) << "404";
    response->setStatus(404);
    return;
  }
  off_t size = st.st_size;
  if (size > HTTPServer::kMaxFileSize) {
    LOG(INFO) << "unsported length";
    response->setStatus(401);
    response->setContent("file size up to server bound");
    return;
  }
  response->setStatus(200);
  response->setContent(std::move(readFile(file_path)));
  LOG(INFO) << request->method << " " << request->request_url << " "
            << "200"
            << " " << size << "\n";
}

}; // namespace qg