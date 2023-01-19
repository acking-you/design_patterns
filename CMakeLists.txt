cmake_minimum_required(VERSION 3.14)
project(clion_pro_template)
set(CMAKE_CXX_STANDARD 17)

option(ENABLE_TEST "Build Test" ON)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

add_library(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

if (ENABLE_TEST)
    add_subdirectory(tests)
endif ()