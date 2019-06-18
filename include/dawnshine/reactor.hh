//
// Created by zhengcf on 2019-05-17.
//

#pragma once

#include <libaio.h>
#include "dawnshine/net_addr.hh"
#include "dawnshine/pollable_fd.hh"
#include "util/utilimpl.hh"

class reactor {
    friend class pollable_fd;

    friend class file;

    static constexpr size_t max_aio = 128;
public:
    reactor(const reactor &) = delete;

    void operator=(const reactor &) = delete;

    reactor();

    pollable_fd listen(socket_address sa, listen_options opts = {});

    std::pair<pollable_fd, socket_address> accept(pollable_fd_state &listen_fd);

private:
    void get_epoll_future(pollable_fd_state &fd, int event);

    void complete_epoll_event(pollable_fd_state &fd, int events, int event);

    void readable(pollable_fd_state &fd);

    void forget(pollable_fd_state &fd);

public:
    file_desc epollfd_;

};


inline
std::pair<pollable_fd, socket_address>
pollable_fd::accept() {
    return reactor_.accept(*s_);
}

inline
pollable_fd::~pollable_fd() {
    reactor_.forget(*s_);
}