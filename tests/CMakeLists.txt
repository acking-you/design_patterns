include(FetchContent)
FETCHCONTENT_DECLARE(
       fmt
        GIT_REPOSITORY https://gitee.com/acking-you/fmt.git
        GIT_TAG 9.1.0
        GIT_SHALLOW TRUE
)
FETCHCONTENT_MAKEAVAILABLE(fmt)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_definitions(-DBASE_DIR=${PROJECT_SOURCE_DIR})

aux_source_directory(${PROJECT_SOURCE_DIR}/tests TEST_FILES)

foreach (path ${TEST_FILES})
    get_filename_component(name ${path} NAME_WLE)
    add_executable(${name} ${path})
    target_link_libraries(${name} PRIVATE ${PROJECT_NAME} fmt::fmt)
    add_test(NAME ${name}-unittest COMMAND unittest)
endforeach ()
target_link_libraries(window_singleton_test PRIVATE Qt5::Widgets)