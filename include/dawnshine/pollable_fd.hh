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
    ~pollable_fd_state();
    explicit pollable_fd_state(reactor& rec, file_desc fd, speculation speculate = speculation())
            : fd(std::move(fd)), events_known(speculate.events), _reactor(rec) {}
    pollable_fd_state(const pollable_fd_state&) = delete;
    void operator=(const pollable_fd_state&) = delete;
    void speculate_epoll(int events) { events_known |= events; }
    file_desc fd;
    int events_requested = 0; // wanted by pollin/pollout promises
    int events_epoll = 0;     // installed in epoll
    int events_known = 0;     // returned from epoll
    promise<> pollin;
    promise<> pollout;
    reactor&  _reactor;
    friend class pollable_fd;
};

class pollable_fd {
public:
    using speculation = pollable_fd_state::speculation;
    std::unique_ptr<pollable_fd_state> _s;
    pollable_fd(file_desc fd, speculation speculate = speculation())
            : _s(std::make_unique<pollable_fd_state>(std::move(fd), speculate)) {}
public:
    pollable_fd(pollable_fd&&) = default;
    pollable_fd& operator=(pollable_fd&&) = default;
    size_t read_some(char* buffer, size_t size);
    size_t read_some(uint8_t* buffer, size_t size);
    size_t read_some(const std::vector<iovec>& iov);
    size_t write_all(const char* buffer, size_t size);
    size_t write_all(const uint8_t* buffer, size_t size);
    std::pair<pollable_fd, socket_address> accept();
protected:
    int get_fd() const { return _s->fd.get(); }
    friend class readable_eventfd;
};

class readable_eventfd {
    pollable_fd _fd;
public:
    explicit readable_eventfd(size_t initial = 0) : _fd(try_create_eventfd(initial)) {}
    future<size_t> wait();
    int get_write_fd() { return _fd.get_fd(); }
private:
    static file_desc try_create_eventfd(size_t initial);
};

class writeable_eventfd {
    file_desc _fd;
public:
    explicit writeable_eventfd(size_t initial = 0) : _fd(try_create_eventfd(initial)) {}
    void signal(size_t nr);
    int get_read_fd() { return _fd.get(); }
private:
    static file_desc try_create_eventfd(size_t initial);
};

