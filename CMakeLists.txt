cmake_minimum_required(VERSION 3.8)
project(vcs-cli)

set(CMAKE_CXX_STANDARD 20)

add_executable(vcs-cli src/main.cc
        src/Repo.cc
        src/Repo.hh
        src/File.cc
        src/File.hh
        src/Push.cc
        src/Push.hh
        src/Branch.cc
        src/Branch.hh
        src/Patch.cc
        src/Patch.hh
)
install(TARGETS vcs-cli DESTINATION /usr/local/bin)
