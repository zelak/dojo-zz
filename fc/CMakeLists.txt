cmake_minimum_required(VERSION 2.8.8)

# project wide definitions
set(PROJECT_NAME fc_oo)
project(${PROJECT_NAME})

# Enable C++11 features
SET(CMAKE_CXX_FLAGS "-std=c++11")

# Unit test
add_executable(${PROJECT_NAME} fc_oo.cc)
