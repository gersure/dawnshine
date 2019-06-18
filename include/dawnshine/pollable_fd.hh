//
// Created by emp on 2019-05-14.
//
#pragma once

#include "dawnshine/posix.hh"
#include "util/utilimpl.hh"

class reactor;

class pollable_fd_state {
public:
    struct speculation {
        int events = 0;

        explicit speculation(int epoll_events_guessed = 0) : events(epoll_events_guessed) {}
    };

    pollable_fd_state(const pollable_fd_state &) = delete;

    void operator=(const pollable_fd_state &) = delete;

    explicit pollable_fd_state(file_desc fd, speculation speculate = speculation())
            : fd_(std::move(fd)),
              events_known_(speculate.events) {}

    void speculate_epoll(int events) { events_known_ |= events; }

protected:
    file_desc fd_;
    int events_requested_ = 0; // wanted by pollin/pollout promises
    int events_epoll_ = 0;     // installed in epoll
    int events_known_ = 0;     // returned from epoll

    friend class pollable_fd;

    friend class reactor;
};

class pollable_fd {
public:
    using speculation = pollable_fd_state::speculation;
    std::unique_ptr<pollable_fd_state> s_;

    pollable_fd(reactor &rec, file_desc fd, speculation speculate = speculation())
            : reactor_(rec),
              s_(std::make_unique<pollable_fd_state>(std::move(fd), speculate)) {}

public:
    pollable_fd(pollable_fd &&) = default;

    pollable_fd &operator=(pollable_fd &&) = default;

    ~pollable_fd();

    std::pair<pollable_fd, socket_address> accept();

    size_t read_some(char *buffer, size_t size);

    size_t read_some(uint8_t *buffer, size_t size);

    size_t read_some(const std::vector<iovec> &iov);

    size_t write_all(const char *buffer, size_t size);

    size_t write_all(const uint8_t *buffer, size_t size);

protected:
    int get_fd() const { return s_->fd_.get(); }

    reactor &reactor_;
};