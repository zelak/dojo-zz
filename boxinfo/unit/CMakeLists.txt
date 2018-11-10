cmake_minimum_required(VERSION 2.8.8)

include_directories(${boxinfo_SOURCE_DIR})
link_directories(${boxinfo_SOURCE_DIR})

###############################
# unit test - boxinfo         #
###############################

set(PROJECT_NAME test_boxinfo)
project(${PROJECT_NAME})

# TODO: fix how to include source files
add_executable(${PROJECT_NAME}
               ../boxinfo_manager.cc
               ../boxinfo_entry.cc
               ../boxinfo_vendor.cc
               ../boxinfo_zanon_read_strategy.cc
               ../boxinfo_zanon.cc
               ../boxinfo.cc
               test_boxinfo.cc)

###############################
# unit test - boxinfo manager #
###############################

set(PROJECT_NAME test_boxinfo_manager)
project(${PROJECT_NAME})

# TODO: fix how to include source files
add_executable(${PROJECT_NAME}
               ../boxinfo_manager.cc
               ../boxinfo_entry.cc
               test_boxinfo_manager.cc)
