cmake_minimum_required(VERSION 3.14)
project(dawnshine)

set(CMAKE_CXX_STANDARD 11)



include_directories(include)




set(SOURCE_FILES
        include/dawnshine/reactor.hh
        include/dawnshine/net_addr.hh
        include/dawnshine/pollable_fd.hh
        include/dawnshine/posix.hh

        src/net_addr.cc
        src/reactor.cc
        include/util/utilimpl.hh)

add_library(dawnshine ${SOURCE_FILES})

add_subdirectory(test)