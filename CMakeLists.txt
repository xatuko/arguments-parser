cmake_minimum_required(VERSION 3.0.0)
project(arg_parser VERSION 0.1.0 LANGUAGES C CXX)

add_executable(arg_parser main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})