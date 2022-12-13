cmake_minimum_required(VERSION 3.15)

set(PROGECT_NAME test)
project("${PROGECT_NAME}")

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENYIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

include_directories("inc/")

add_executable("${PROGECT_NAME}" practice4.cpp)

								
