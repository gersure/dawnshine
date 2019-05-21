//
// Created by zhengcf on 2019-05-16.
//

#include <cstring>
#include "dawnshine/net_addr.hh"

socket_address make_ipv4_address(ipv4_addr addr)
{
    socket_address sa;
    sa.u.in.sin_family = AF_INET;
    sa.u.in.sin_port = htons(addr.port);
    std::memcpy(&sa.u.in.sin_addr, &addr.host, 4);
    return sa;
}

socket_address make_ipv4_address(const std::string saddr, uint16_t port)
{
    ipv4_addr addr;
    addr.host = inet_addr(saddr.c_str());
    addr.port = port;
    return make_ipv4_address(addr);
}

std::ostream& operator<<(std::ostream& ost,const socket_address& sockaddr)
{
    ost<<inet_ntoa(sockaddr.u.in.sin_addr)<<":"<<sockaddr.u.in.sin_port;

    return ost;
}