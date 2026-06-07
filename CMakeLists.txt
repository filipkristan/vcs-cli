cmake_minimum_required(VERSION 3.8)
project(vcs-cli)

set(CMAKE_CXX_STANDARD 20)

add_executable(vcs-cli src/main.cc
        src/xit.cc
        src/xit.hh
        src/FileOperations.cc
        src/FileOperations.hh
        src/PushRepoOperations.cc
        src/PushRepoOperations.hh
)
install(TARGETS vcs-cli DESTINATION /usr/local/bin)
