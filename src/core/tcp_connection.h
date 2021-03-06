//
// Created by wc on 5/6/19.
//

#ifndef SRC_CORE_TCP_CONNECTION_H_
#define SRC_CORE_TCP_CONNECTION_H_
#include "../util/noncopyable.h"
#include "../util/type.h"
#include "./socket.h"
#include <any>
#include <functional>
#include <glog/logging.h>
#include <string>
#include <utility>

namespace qg {
class EventLoop;

class EventHandler;

class Accepter;

// 这里设置TcpConnection为enable_shared_from_this是为了控制tcpconnection的生命周期，避免Connection在
// handleEvent的时候被析构。
class TcpConnection : public std::enable_shared_from_this<TcpConnection> {
public:
  typedef std::string buf_t;
  typedef Socket *socket_pt;
  typedef EventLoop *event_loop_pt;
  typedef EventHandler *event_handler_pt;

  explicit TcpConnection(event_loop_pt el, std::unique_ptr<Socket> socket,
                         Accepter *accpeter);

  ~TcpConnection();

  void handleConnection();

  void handleRead();

  void handleWrite();

  void handleClose();

  void closeConnection();

  qg_fd_t fd() const { return socket_->sfd(); }
  EventLoop* getLoop() const {return event_loop_;}

  void setMessageCallBack(MessageCallBack cb) {
    this->message_call_back_ = std::move(cb);
  }
  void setWriteCompleteCallBack(WriteCompleteCallBack cb) {
    this->write_complete_call_back_ = std::move(cb);
  }
  void setConnectionComeCallBack(ConnectionComeCallBack cb) {
    this->connection_come_call_back_ = std::move(cb);
  }
  void setConnectionCloseCallBack(ConnectionCloseCallBack cb) {
    this->connection_close_call_back_ = std::move(cb);
  }
  std::any context() const { return context_; }
  void setContext(std::any context) { context_ = std::move(context); }
  void write(const buf_t& str);
  void writeInLoop(const buf_t& str);
  void sendFile(const qg_string &file_name);
  void sendFile(qg_fd_t fd) {
    // TODO(qinggniq) : 在Linux下面用sendfile实现。
  }
  bool hasContentToSend() const {
    return !write_buf_.empty() || sendfile_fd_ >= 0;
  }
  void shutdown() {
    socket_->shutdown();
  }

  void close();

  event_handler_pt eventHandler() { return event_handler_; }

  static int defaultReadBuffSize;

private:
  static int kMaxFileSize;

private:
  event_loop_pt event_loop_;
  std::unique_ptr<Socket> socket_;
  event_handler_pt event_handler_;
  Accepter *accpeter_;
  bool disconnected_;
  bool closed_;
  qg_fd_t sendfile_fd_;
  buf_t read_buf_;
  buf_t write_buf_;
  std::any context_;
  MessageCallBack message_call_back_;
  WriteCompleteCallBack write_complete_call_back_;
  ConnectionComeCallBack connection_come_call_back_;
  ConnectionCloseCallBack connection_close_call_back_;
};
} // namespace qg

#endif // SRC_CORE_TCP_CONNECTION_H_
