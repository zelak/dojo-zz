cmake_minimum_required(VERSION 2.8.8)

# project wide definitions
set(PROJECT_NAME boxinfo)
project(${PROJECT_NAME})
subdirs(unit)

# Enable C++11 features, Fuse version and Fuse define D_FILE_OFFSET_BITS
SET(CMAKE_CXX_FLAGS "-std=c++11 -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64")

# include FUSE library
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

find_package(FUSE 2.6 REQUIRED)
include_directories(${FUSE_INCLUDE_DIR})
link_libraries(${FUSE_LIBRARIES})

# boxinfo: main binary
add_executable(${PROJECT_NAME} boxinfo_entry.cc boxinfo_arris_entry.cc boxinfo_manager.cc boxinfo.cc main.cc)
