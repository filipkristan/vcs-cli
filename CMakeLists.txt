cmake_minimum_required(VERSION 3.8)
project(xit)

set(CMAKE_CXX_STANDARD 20)

add_executable(xit main.cc
        xit.cc
        xit.hh
        FileOperations.cc
        FileOperations.hh
        pushRepoOperations.cc
        pushRepoOperations.hh
)
install(TARGETS xit DESTINATION /usr/local/bin)
