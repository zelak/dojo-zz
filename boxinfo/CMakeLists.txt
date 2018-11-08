cmake_minimum_required(VERSION 2.8.8)

# project wide definitions
set(PROJECT_NAME boxinfo)
project(${PROJECT_NAME})
#subdirs(unit)

set(GCC_COVERAGE_COMPILE_FLAGS "-fPIC")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -DFLAVOUR_telefonica_openmw -D__VIP52X2B32__")

link_libraries(fuse TLFBootloaderAPI)

# boxinfo: main binary
add_executable(${PROJECT_NAME} boxinfo_entry.cc boxinfo_casn_entry.cc boxinfo_csc_entry.cc boxinfo_tlf_entry.cc boxinfo_arris_entry.cc boxinfo_manager.cc boxinfo.cc main.cc)
