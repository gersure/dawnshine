//
// Created by zhengcf on 2019-05-17.
//

#include "dawnshine/net_addr.hh"
#include "dawnshine/reactor.hh"

reactor::reactor()
        : epollfd_(file_desc::epoll_create(EPOLL_CLOEXEC))
//          _io_eventfd(),
//          _io_context(0),
//          _io_context_available(max_aio)
          {
//    auto r = ::io_setup(max_aio, &_io_context);
//    assert(r >= 0);
//    _io_eventfd.wait()

}

pollable_fd reactor::listen(socket_address sa, listen_options opts) {
    file_desc fd = file_desc::socket(sa.u.sa.sa_family, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
    if (opts.reuse_address) {
        int opt = 1;
        fd.setsockopt(SOL_SOCKET, SO_REUSEADDR, opt);
    }

    fd.bind(sa.u.sa, sizeof(sa.u.sas));
    fd.listen(100);
    return pollable_fd(*this, std::move(fd));
}

#if 0
void reactor::run() {
    std::array<epoll_event, 128> eevt;
    int nr = ::epoll_wait(epollfd_.get(), eevt.data(), eevt.size(), -1);
    assert(nr != -1);
    for (int i = 0; i < nr; i++) {
        auto &evt = eevt[i];
        auto pfd = reinterpret_cast<pollable_fd_state *>(evt.data.ptr);
        auto events = evt.events & (EPOLLIN | EPOLLOUT);
        std::unique_ptr<task> t_in, t_out;
        pfd->events_known |= events;
        auto events_to_remove = events & ~pfd->events_requested;
        complete_epoll_event(*pfd, &pollable_fd_state::pollin, events, EPOLLIN);
        complete_epoll_event(*pfd, &pollable_fd_state::pollout, events, EPOLLOUT);
        if (events_to_remove) {
            pfd->events_epoll &= ~events_to_remove;
            evt.events = pfd->events_epoll;
            auto op = evt.events ? EPOLL_CTL_MOD : EPOLL_CTL_DEL;
            ::epoll_ctl(epollfd_.get(), op, pfd->fd.get(), &evt);
        }
    }
}
#endif

std::pair<pollable_fd, socket_address>
reactor::accept(pollable_fd_state &listen_fd) {
    readable(listen_fd);
    socket_address sa;
    socklen_t sl = sizeof(&sa.u.sas);
    file_desc fd = listen_fd.fd.accept(sa.u.sa, sl, SOCK_NONBLOCK | SOCK_CLOEXEC);
    pollable_fd pfd(*this, std::move(fd), pollable_fd::speculation(EPOLLOUT));
    return std::pair<pollable_fd, socket_address>(std::move(pfd), std::move(sa));
}


void reactor::get_epoll_future(pollable_fd_state &pfd, int event) {
    if (pfd.events_known & event) {
        pfd.events_known &= ~event;
        return;
    }
    pfd.events_requested |= event;
    if (!(pfd.events_epoll & event)) {
        auto ctl = pfd.events_epoll ? EPOLL_CTL_MOD : EPOLL_CTL_ADD;
        pfd.events_epoll |= event;
        ::epoll_event eevt;
        eevt.events = pfd.events_epoll;
        eevt.data.ptr = &pfd;
        int r = ::epoll_ctl(epollfd_.get(), ctl, pfd.fd_.get(), &eevt);
        assert(r == 0);
    }
    return;
}


void reactor::readable(pollable_fd_state &fd) {
    return get_epoll_future(fd, EPOLLIN);
}

void reactor::forget(pollable_fd_state &fd) {
    if (fd.events_epoll) {
        ::epoll_ctl(epollfd_.get(), EPOLL_CTL_DEL, fd.fd_.get(), nullptr);
    }
}
