//
// Created by emp on 2019-05-14.
//

#pragma once

#include <cstdint>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ostream>

struct listen_options {
    bool reuse_address = false;
};

struct ipv4_addr {
    uint32_t host;
    uint16_t port;
};

class socket_address {
public:
    union {
        ::sockaddr_storage sas;
        ::sockaddr sa;
        ::sockaddr_in in;
    } u;
    friend std::ostream& operator<<(std::ostream&,const socket_address&);
    friend socket_address make_ipv4_address(ipv4_addr addr);
    friend socket_address make_ipv4_address(const std::string addr);
    friend class reactor;
};

std::ostream& operator<<(std::ostream&,const socket_address&);
socket_address make_ipv4_address(ipv4_addr addr);
socket_address make_ipv4_address(const std::string addr);
