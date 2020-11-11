cmake_minimum_required(VERSION 3.5)

project(utils LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(utils
    main.cpp
    bit_cast.hpp
    bit_cast14.hpp)
