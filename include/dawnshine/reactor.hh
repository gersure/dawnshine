//
// Created by zhengcf on 2019-05-17.
//

#pragma once

#include <libaio.h>
#include "dawnshine/net_addr.hh"
#include "dawnshine/pollable_fd.hh"
#include "util/utilimpl.hh"

class reactor {
    static constexpr size_t max_aio = 128;
public:
    file_desc _epollfd;
//    readable_eventfd _io_eventfd;
//    io_context_t _io_context;
//    semaphore _io_context_available;
private:
    void get_epoll_future(pollable_fd_state& fd, int event);
    void complete_epoll_event(pollable_fd_state& fd, int events, int event);
    void readable(pollable_fd_state& fd);
//    void writeable(pollable_fd_state& fd);
    void forget(pollable_fd_state& fd);
//    void abort_on_error(int ret);
public:
    reactor();
    reactor(const reactor&) = delete;
    void operator=(const reactor&) = delete;

    pollable_fd listen(socket_address sa, listen_options opts = {});

    std::pair<pollable_fd, socket_address> accept(pollable_fd_state& listen_fd);

#if 0
    size_t read_some(pollable_fd_state& fd, void* buffer, size_t size);
    size_t read_some(pollable_fd_state& fd, const std::vector<iovec>& iov);

    size_t write_some(pollable_fd_state& fd, const void* buffer, size_t size);

    size_t write_all(pollable_fd_state& fd, const void* buffer, size_t size);

    file open_file_dma(sstring name);
    void flush(file& f);

    void run();

    void add_task(std::unique_ptr<task>&& t) { _pending_tasks.push_back(std::move(t)); }
#endif

private:
#if 0
    size_t write_all_part(pollable_fd_state& fd, const void* buffer, size_t size, size_t completed);

    size_t read_dma(file& f, uint64_t pos, void* buffer, size_t len);
    size_t read_dma(file& f, uint64_t pos, std::vector<iovec> iov);
    size_t write_dma(file& f, uint64_t pos, const void* buffer, size_t len);
    size_t write_dma(file& f, uint64_t pos, std::vector<iovec> iov);

    template <typename Func>
    future<io_event> submit_io(Func prepare_io);

    void process_io(size_t count);
#endif
    friend class pollable_fd;
    friend class pollable_fd_state;
    friend class file;
//    friend class thread_pool;
};

inline
std::pair<pollable_fd, socket_address> pollable_fd::accept() {
    return (*_s)._reactor.accept(*_s);
}