//
// Created by wc on 2/15/19.
//

#ifndef SRC_EVENT_HANDLER_INHERIT_H
#define SRC_EVENT_HANDLER_INHERIT_H

#include "../util/type.h"
#include <boost/function.hpp>
#include <sys/epoll.h>

namespace qg{
typedef qg_uint events_t;
typedef fd_t handle_t;

enum EventMode {
  kEventNone=0x00,
  kEventRead = EPOLLIN,
  kEventWrite = EPOLLOUT,
  kEventError = EPOLLERR,
  kEventMask = 0xff
};

/* You could not implement the read/write handle of file describer,
 * but you must implement the error handle.
*
 */
struct EventStatus{
  qg_fd_t fd;
  qg_uint revents;
};


class EventHandler {
 public:
  virtual void HandleEvent();

  handle_t GetHandle() const;
  void SetHandle(const handle_t &handle);

  events_t GetIEvent() const;
  void SetIEvents(const events_t &iev);
  void SetREvents(const events_t &rev);

  qg_bool IsReadable() const;
  qg_bool IsWriteable() const;
  qg_bool IsError() const;

 protected:
  EventHandler(qg_int fd, events_t ie);
  ~EventHandler() = default ;

  handle_t handle_;
  events_t ievents_; //interest events
  events_t revents_; //the result of sync_event_demuliplexer(epoll) returned
  virtual void HandleRead() = 0;
  virtual void HandleWrite() = 0;
  virtual void HandleError() = 0;
};



inline
void
EventHandler::SetHandle(const qg::handle_t &handle) {
  this->handle_ = handle;
}

inline
handle_t
EventHandler::GetHandle() const {
  return this->handle_;
}

inline
events_t
EventHandler::GetIEvent() const {
  return this->ievents_;
}

inline
void
EventHandler::SetIEvents(const qg::events_t &iev) {
  this->ievents_ = iev;
}

inline
void
EventHandler::SetREvents(const qg::events_t &rev) {
  this->revents_ = rev;
}


inline
qg_bool
EventHandler::IsReadable() const {
  return this->revents_ & EventMode ::kEventRead;
}

inline
qg_bool
EventHandler::IsWriteable() const {
  return this->revents_ & EventMode ::kEventWrite;
}

inline
qg_bool
EventHandler::IsError() const {
  return this->revents_ & EventMode ::kEventError;
}

}//namespace qg
#endif //SRC_EVENT_HANDLER_INHERIT_H