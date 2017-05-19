cmake_minimum_required(VERSION 2.8)

project (2Lab-8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(HEADERS ${PROJECT_SOURCE_DIR}/include/2Lab-8.hpp)
set(HEADERS ${PROJECT_SOURCE_DIR}/include/catch.hpp)
set(SOURCES ${PROJECT_SOURCE_DIR}/sources/2Lab-8.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library (${PROJECT_NAME} STATIC ${SOURCES})

add_subdirectory(tests)
add_subdirectory(example)
