find_package(Qt5 COMPONENTS Widgets REQUIRED)


add_definitions(-DBASE_DIR="${PROJECT_SOURCE_DIR}")

aux_source_directory(${PROJECT_SOURCE_DIR}/tests TEST_FILES)

foreach (path ${TEST_FILES})
    get_filename_component(name ${path} NAME_WLE)
    add_executable(${name} ${path})
    target_link_libraries(${name} PRIVATE ${PROJECT_NAME})
    add_test(NAME ${name}-unittest COMMAND unittest)
endforeach ()

if (Qt5_FOUND)
    target_link_libraries(window_singleton_test PRIVATE Qt5::Widgets)
    target_link_libraries(decorator_2_test PRIVATE Qt5::Widgets)
else()
    message(WARNING "Qt5 is not found, and the code involved in the UI part will not run")
endif ()