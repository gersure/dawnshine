//
// Created by zhengcf on 2019-05-16.
//

#include "dawnshine/net_addr.hh"

socket_address make_ipv4_address(ipv4_addr addr)
{
    socket_address sa;
    sa.u.in.sin_family = AF_INET;
    sa.u.in.sin_port = htons(addr.port);
    sa.u.in.sin_addr = addr.host;
    return sa;
}

socket_address make_ipv4_address(const std::string addr, uint16_t port)
{
    ipv4_addr addr;
    addr.host = inet_addr(add.c_str());
    addr.port = port;
    return make_ipv4_address(addr);
}