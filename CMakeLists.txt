cmake_minimum_required(VERSION 3.14 )
project(design_patterns)
set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FETCHCONTENT_DECLARE(
        fmt
        GIT_REPOSITORY https://gitee.com/acking-you/fmt.git
        GIT_TAG 9.1.0
        GIT_SHALLOW TRUE
)
FETCHCONTENT_MAKEAVAILABLE(fmt)

FETCHCONTENT_DECLARE(
        ejson
        GIT_REPOSITORY https://gitee.com/acking-you/ejson4cpp.git
        GIT_TAG origin/master
        GIT_SHALLOW TRUE
)
FETCHCONTENT_MAKEAVAILABLE(ejson)

option(ENABLE_${PROJECT_NAME}_TEST "Build Test" ON)

message(STATUS ${ENABLE_${PROJECT_NAME}_TEST})

file(GLOB_RECURSE SRC ${PROJECT_SOURCE_DIR}/src/*.h ${PROJECT_SOURCE_DIR}/src/*.cc)

add_library(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC   src)
target_link_libraries(${PROJECT_NAME} ejson fmt)

if (ENABLE_TEST)
    add_subdirectory(tests)
endif ()