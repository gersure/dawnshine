//
// Created by zhengcf on 2019-05-21.
//

#include <iostream>
#include "dawnshine/reactor.hh"

class connection;
class http_server {
    std::vector<pollable_fd> _listeners;
public:
    void listen(ipv4_addr addr) {
        listen_options lo;
        lo.reuse_address = true;
        _listeners.push_back(reactor_.listen(make_ipv4_address(addr), lo));
        do_accepts(_listeners.size() - 1);
    }

    void do_accepts(int which) {
        std::pair<pollable_fd, socket_address> res = _listeners[which].accept();
        new connection(*this, std::move(res.first), res.second);
        std::cout<<"accept from:"<< res.second << std::endl;
    }

    class connection {
        http_server &_server;
        pollable_fd _fd;
        socket_address _addr;
        bool _eof = false;
        static constexpr size_t limit = 4096;
    public:
        connection(http_server &server, pollable_fd &&fd, socket_address addr)
                : _server(server), _fd(std::move(fd)), _addr(addr){}

    };

private:
    reactor reactor_;
};

int main(int ac, char *av[])
{
    http_server server;
    server.listen({0, 10000});

}