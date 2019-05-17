//
// Created by emp on 2019-05-14.
//

#pragma once

#include <cstdint>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include<netinet/in.h>

struct listen_options {
    bool reuse_address = false;
};

struct ipv4_addr {
    uint32_t host;
    uint16_t port;
};

class socket_address {
private:
    union {
        ::sockaddr_storage sas;
        ::sockaddr sa;
        ::sockaddr_in in;
    } u;
    friend socket_address make_ipv4_address(ipv4_addr addr);
    friend socket_address make_ipv4_address(const std::string addr);
    friend class reactor;
};


socket_address make_ipv4_address(ipv4_addr addr);
socket_address make_ipv4_address(const std::string addr);
