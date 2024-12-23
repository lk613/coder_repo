cmake_minimum_required(VERSION 3.5.0)
project(code_repo VERSION 0.1.0 LANGUAGES C)

add_executable(code_repo main.c)

include(CTest)
enable_testing()

