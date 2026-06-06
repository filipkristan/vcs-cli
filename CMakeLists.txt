cmake_minimum_required(VERSION 3.8)
project(xit)

set(CMAKE_CXX_STANDARD 20)

add_executable(xit src/main.cc
        src/xit.cc
        src/xit.hh
        src/FileOperations.cc
        src/FileOperations.hh
        src/pushRepoOperations.cc
        src/pushRepoOperations.hh
)
install(TARGETS xit DESTINATION /usr/local/bin)
