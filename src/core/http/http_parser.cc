//
// Created by wc on 1/15/19.
//

#include "http_parser.h"

#include <iostream>

#include "type.h"
#include "http_data.h"


namespace qg {


RequestParser::~RequestParser() = default;

RequestParser::ok_t
RequestParser::Parse(const msg_t &http_msg) {
  return kOk;
}

RequestParser::ok_t
RequestParser::Parse(qg_istream &stream) {
  qg_string line;
  method_t method;
  version_t version;
  qg_string query_s;
  header_t header;
  body_t body;

  uri_t uri;

  getline(stream, line);
  size_t method_end = qg_string::npos;

  if ((method_end = line.find(' ')) != qg_string::npos) {
    method = line.substr(0, method_end);

    qg::qg_size_t query_start = qg_string::npos;
    qg::qg_size_t uri_and_query_end = qg_string::npos;
    qg::qg_size_t line_size = line.size();

    for (qg::qg_size_t i = method_end + 1; i < line_size; ++i) {
      if ( i < line_size - 1 && line[i] == '?') {
        query_start = i;
      } else if (line[i] == ' ') {
        uri_and_query_end = i;
        break;
      }
    }
    //parse file
    qg_ssize_t file_pos = line.find("/", method_end);
    if (file_pos == qg_string::npos) {
      request_d_->set_file("index.html");
    }
    if (file_pos != qg_string::npos) {
      qg_ssize_t tmp_pos = line.find(' ', file_pos);
      if (tmp_pos == qg_string::npos) {
        error_code_ = ErrorCode ::kQueryError;
        return kError;
      }else {
        if (tmp_pos - file_pos > 1) {
          qg_string file = line.substr(file_pos + 1, tmp_pos-file_pos-1);
          qg_ssize_t _query_start = file.find("?");
          if (_query_start != qg_string::npos) {
            file = file.substr(0, _query_start);
          }
          request_d_->set_file(file);
        }else{
          request_d_->set_file("index.html");
        }
      }
    }

    if (uri_and_query_end != qg_string::npos) {
      if (query_start != qg_string::npos) {
        uri = line.substr(method_end + 1, query_start);
        query_s = line.substr(query_start, uri_and_query_end - method_end);
      } else {
        uri = line.substr(method_end + 1, uri_and_query_end - method_end);
      }


      qg::qg_size_t version_end;
      if ((version_end = line.find('/', uri_and_query_end + 1)) != qg_string::npos) {
        if (line.compare(uri_and_query_end + 1, version_end - uri_and_query_end - 1, "HTTP") != 0) {
          error_code_ = ErrorCode ::kProtoclError;
          return kError;
        }
        version = line.substr(version_end + 1, line.size() - version_end - 1);
      } else {
        error_code_ = ErrorCode ::kQueryError;
        return kError;
      }

      this->request_d_->set_methd(method);
      this->request_d_->set_version(version);
      this->request_d_->set_uri(uri);

      return this->ParseHeader(stream) && this->ParseQuery(query_s);
    }

  }
  return kOk;
}



RequestParser::ok_t
RequestParser::ParseHeader(qg::qg_istream &istream) {
  qg_string line;
  header_t header;
  while (getline(istream, line)) {
    qg_size_t key_end;
    if ((key_end = line.find(":")) != qg_string::npos && line.length()) {
      this->request_d_->set_header_item(line.substr(0, key_end), line.substr(key_end + 1, line.length()));
    }
  }

  return this->ParseBody(istream);
}

RequestParser::ok_t
RequestParser::ParseBody(const qg::RequestParser::msg_t &body_msg) {
  return kOk;
}

RequestParser::ok_t
RequestParser::ParseBody(qg::qg_istream &istream) {
  if (((this->request_d_)->Encoded()) == kOk) {
    return kOk;
    //TODO(qinggniq) implement the encode/decode function
  } else {
    return kOk;
    //TODO(qinggniq) implement the body parse function
  }
  return kOk;
}

void
RequestParser::Print() const {
  std::cout << "Http Data:" << std::endl;
  std::cout << "Http Method:" << this->request_d_->method() << std::endl;
  std::cout << "Http Uri:" << this->request_d_->uri() << std::endl;
  std::cout << "Http Version:" << this->request_d_->version() << std::endl;
  std::cout << "Http Headers:" << std::endl;
  RequestData::header_t header = this->request_d_->header();
  for (auto it = header.begin(); it != header.end(); it++) {
    std::cout << it->first << " : " << it->second << std::endl;
  }
  std::cout << "Http Data End!" << std::endl;
}
} //namespace qg