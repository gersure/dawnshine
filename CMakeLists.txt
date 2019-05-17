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
        library.h
        library.cpp
        include/util/utilimpl.hh src/reactor.cc test/test_aio.cc)

add_library(dawnshine ${SOURCE_FILES})

add_subdirectory(test)