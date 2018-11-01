cmake_minimum_required(VERSION 2.8.8)

# project wide definitions
set(PROJECT_NAME boxinfo)
project(${PROJECT_NAME})
subdirs(unit)

# Enable C++11 features
SET(CMAKE_CXX_FLAGS "-std=c++11")

# Unit test
add_executable(${PROJECT_NAME} boxinfo_entry.cc boxinfo_manager.cc boxinfo.cc main.cc)
