include(FetchContent)

#for test
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://gitee.com/acking-you/googletest.git
        GIT_TAG release-1.12.1
        GIT_SHALLOW TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#for benchmark
FetchContent_Declare(
        nanobench
        GIT_REPOSITORY https://gitee.com/acking-you/nanobench.git
        GIT_TAG v4.1.0
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(nanobench)

add_definitions(-DBASE_DIR="../../")

aux_source_directory(${PROJECT_SOURCE_DIR}/tests TEST_FILES)

add_executable(unittest ${TEST_FILES} ${SRC})
target_link_libraries(unittest PRIVATE gtest_main nanobench)
target_include_directories(unittest PRIVATE ${PROJECT_SOURCE_DIR}/tests ${PROJECT_SOURCE_DIR}/include)
add_test(NAME ${PROJECT_NAME}-unittest COMMAND unittest)