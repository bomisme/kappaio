cmake_minimum_required(VERSION 2.8.10)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
#set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)

project(zdo C CXX)

include(FindPkgConfig)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../kapi build/kapi)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../hal build/hal)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../aps build/aps)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -x c++ -std=c++11 -pedantic -D__LITTLE_ENDIAN__")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -D__LITTLE_ENDIAN__")

include_directories(include)
file(GLOB CPP_FILES source/*.cpp)
file(GLOB C_FILES source/*.c)
add_library(${PROJECT_NAME} SHARED ${CPP_FILES} ${C_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} kapi hal aps)
set_property(TARGET ${PROJECT_NAME} PROPERTY VERSION "0.1.0")
set_property(TARGET ${PROJECT_NAME} PROPERTY SOVERSION 0)

