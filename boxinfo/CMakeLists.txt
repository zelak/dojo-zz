cmake_minimum_required(VERSION 2.8.8)

# project wide definitions
set(PROJECT_NAME boxinfo)
project(${PROJECT_NAME})

if(${USE_UNITTEST})
    subdirs(unit)
endif()

#if(${USE_ZANON})
    set(USE_FLAGS "-DUSE_ZANON")
    file(GLOB_RECURSE ZANON_SOURCES "boxinfo_zanon*.cc")
#endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 ${USE_FLAGS}")

# FUSE includes and library path for MACOSX
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    message ( "-- MACOSX: setting FUSE include and library path" )
    include_directories(/usr/local/include/)
    link_directories(/usr/local/lib/)
endif()

# FUSE includes and library path for LINUX
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message ( "-- LINUX/UNIX: setting FUSE include and library path" )
endif()

link_libraries(fuse)

# boxinfo: main binary
add_executable(${PROJECT_NAME}
               ${ZANON_SOURCES}
               boxinfo_vendor.cc
               boxinfo_entry.cc
               boxinfo_manager.cc
               boxinfo.cc
               main.cc)
