cmake_minimum_required(VERSION 3.30.0)
project(LAB3 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(LAB3 main.cpp)

target_include_directories(LAB3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})