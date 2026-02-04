cmake_minimum_required(VERSION 3.20)
project(untitled4)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled4 main.cpp)

# 关键修复：直接强制链接 pqxx 库
# (在 Ubuntu 下，这就相当于告诉编译器加上 -lpqxx 参数)
target_link_libraries(untitled4 pqxx)