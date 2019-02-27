//
// Created by wc on 1/15/19.
//

#ifndef QG_SERVER_TYPE_H
#define QG_SERVER_TYPE_H

#include <string>
#include <sys/socket.h>

namespace qg{
using qg_short = short;
using qg_uint = unsigned int;
using qg_size_t = size_t ;
using qg_ssize_t = ssize_t ;
using qg_time_t = time_t ;
using qg_int = int;
using qg_long = long;
using qg_longlong = long long;
using qg_istream = std::istream;
using qg_string = std::string;
using qg_bool = int;
using qg_fd_t = qg_int;
using qg_event_t = qg_int;
using qg_char_t = char;

const qg_int kError = -1;
const qg_int kOk = 0;
const qg_int kTrue = 1;
const qg_int kFalse = 0;


//network




} //namespace qg
#endif //QG_SERVER_TYPE_H
