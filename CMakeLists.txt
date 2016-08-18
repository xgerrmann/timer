cmake_minimum_required(VERSION 2.8.4)

# About this project
#-------------------
project(timer)

# Use c++11
SET(CMAKE_CXX_FLAGS "-std=c++0x")

## Add headers and source files
#-------------------
set (${PROJECT_NAME}_headers ./timer.hpp)
set (${PROJECT_NAME}_sources ./timer_test.cpp)

## Add subfolders
#-------------------
#add_subdirectory(...)

# Create binaries
#-------------------
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_sources})

add_executable(timer_test ${${PROJECT_NAME}_sources})

