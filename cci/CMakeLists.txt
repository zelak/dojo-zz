cmake_minimum_required(VERSION 2.8.8)

### Exercise 1.1
# project wide definitions
set(PROJECT_NAME cci1_1)
project(${PROJECT_NAME})

# Enable C++11 features
SET(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(${PROJECT_NAME} cci1_1.cc)

### Exercise 1.2
# project wide definitions
set(PROJECT_NAME cci1_2)
project(${PROJECT_NAME})

# Enable C++11 features
SET(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(${PROJECT_NAME} cci1_2.cc)
