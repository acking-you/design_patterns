cmake_minimum_required(VERSION 3.14 )
project(design_patterns)
set(CMAKE_CXX_STANDARD 20)

option(ENABLE_TEST "Build Test" ON)

file(GLOB_RECURSE SRC ${PROJECT_SOURCE_DIR}/src/*.h ${PROJECT_SOURCE_DIR}/src/*.cc)

add_library(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC   src)

if (ENABLE_TEST)
    add_subdirectory(tests)
endif ()