cmake_minimum_required(VERSION 2.8.8)

include_directories(${boxinfo_SOURCE_DIR})
link_directories(${boxinfo_SOURCE_DIR})

###############################
# unit test - boxinfo         #
###############################

set(PROJECT_NAME test_boxinfo)
project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} ../boxinfo_arris_entry.cc ../boxinfo_entry.cc ../boxinfo_manager.cc ../boxinfo.cc test_boxinfo.cc)

###############################
# unit test - boxinfo manager #
###############################

set(PROJECT_NAME test_boxinfo_manager)
project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} ../boxinfo_arris_entry.cc ../boxinfo_entry.cc ../boxinfo_manager.cc test_boxinfo_manager.cc)
