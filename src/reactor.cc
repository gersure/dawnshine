//
// Created by zhengcf on 2019-05-17.
//

#include "dawnshine/net_addr.hh"
#include "dawnshine/reactor.hh"

reactor::reactor()
    :_epollfd(file_desc::epoll_create(EPOLL_CLOEXEC)),
    _io_eventfd(),
    _io_context(0),
    _io_context_available(max_aio)
{
    auto r = ::io_setup(max_aio, &_io_context);
    assert( r >= 0);
    _io_eventfd.wait()

}

pollable_fd reactor::listen(socket_address sa, listen_options opts) {
    file_desc fd = file_desc::socket(sa.u.sa.sa_family, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
    if ( opts.reuse_address ) {
        int opt = 1;
        fd.setsockopt(SOL_SOCKET, SO_REUSEADDR, opt);
    }

    fd.bind(sa.u.sa, sizeof(sa.u.sas));
    fd.listen(100);
    return pollable_fd(std::move(fd));
}

