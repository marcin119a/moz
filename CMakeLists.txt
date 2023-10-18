cmake_minimum_required(VERSION 3.25)
project(MOZ)

set(CMAKE_CXX_STANDARD 17)

add_executable(MOZ main.cpp prog/moz.cpp)
