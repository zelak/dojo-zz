cmake_minimum_required(VERSION 2.8.8)

###############################
# unit test - boxinfo manager #
###############################

set(PROJECT_NAME test_boxinfo_manager)
project(${PROJECT_NAME})

include_directories(${boxinfo_SOURCE_DIR})
link_directories(${boxinfo_SOURCE_DIR})

add_executable(${PROJECT_NAME} ../boxinfo_entry.cc ../boxinfo_manager.cc test_boxinfo_manager.cc)

