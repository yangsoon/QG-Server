//
// Created by 王聪 on 2020/3/7.
//

#include "Pollpoller.h"
#include "../event_handler.h"
#include <glog/logging.h>
#include <iostream>
#include <sys/poll.h>

using namespace qg;
Pollpoller::Pollpoller() : Poller() {}

void qg::Pollpoller::updateHandler(qg::Poller::handler h) {
  int index = h->Index();

  if (index < 0) {
    registerHandler(h);
  }else{
    this->fds[index].events = h->getIEvents();
    this->fds[index].revents = 0;
  }

}

void qg::Pollpoller::registerHandler(qg::Poller::handler h) {
  assert(h->Index() < 0);
  h->SetIndex(fds.size());
  event_handler_map_[h->getHandle()] = h;
  struct pollfd pfd;
  pfd.fd = h->getHandle();
  pfd.events = h->getIEvents();
  pfd.revents = 0;
  fds.push_back(pfd);
  event_handler_map_.emplace(h->getHandle(), h);
}

void qg::Pollpoller::removeHandler(qg::Poller::handler h) {
  int index = h->Index();
  assert(index >= 0 && index < this->fds.size());
  assert(event_handler_map_[h->getHandle()] == h);
  assert(fds[index].revents == 0);
  LOG(INFO) << "set index from " << event_handler_map_[fds.back().fd]->Index()
            << " to " << index;
  // index 是Eventhandler的东西，在删除的时候我们不能移动位置。。
  event_handler_map_[fds.back().fd]->SetIndex(index);
  event_handler_map_.erase(h->getHandle());
  std::swap(fds[index], fds.back());
  fds.pop_back();
}

std::vector<qg::Poller::handler> qg::Pollpoller::Wait(int sz,
                                                      TimeStamp time_stamp) {
  //可能需要为0的时刻。。
  std::vector<qg::Poller::handler> res;
  //在这里可能会出现问题，
  qg_int wait_time = -1;
  if (time_stamp.getUnixTimeStamp() != 0) {
    wait_time = time_stamp.toMilliseconds();
  }else{
    LOG(INFO) << "wait forerver";
    // wait_time = 1000; //1s
  }
  if (sz < 0) {
    sz = fds.size();
  } else {
    sz = sz > fds.size() ? fds.size() : sz;
  }
  int n = ::poll(fds.data(), sz, wait_time);
  if (n < 0) {
    switch (errno) {
    case EINVAL:
      LOG(ERROR) << "ndfs greater than " << FD_SETSIZE;
      break;
    default:
      LOG(ERROR) << "other error";
    }
  }

  for (auto &pfd : fds) {
    if (pfd.revents != 0) {
      LOG(WARNING) << "event coming";
      auto handler = event_handler_map_.find(pfd.fd);
      assert(handler != event_handler_map_.end());
      handler->second->setREvents(pfd.revents);
      LOG(INFO) << "remove the revents";
      res.emplace_back(handler->second);
      n--;
    }
    if (n == 0) {
      break;
    }
  }
  return res;
}
