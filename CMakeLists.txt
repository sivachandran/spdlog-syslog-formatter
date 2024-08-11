cmake_minimum_required(VERSION 3.10)

project(spdlog-syslog-formatter)

find_package(spdlog CONFIG REQUIRED)

add_executable(example example/main.cpp)

target_link_libraries(example PRIVATE spdlog::spdlog)
target_include_directories(example PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
