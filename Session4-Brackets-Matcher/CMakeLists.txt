cmake_minimum_required(VERSION 3.3)
project(Session_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES stack.c stack.h main.c bracketEval.c bracketEval.h main.h)
add_executable(Session_4 ${SOURCE_FILES})