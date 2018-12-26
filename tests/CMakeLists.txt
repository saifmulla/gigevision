
ExternalProject_Add(googletest
    STAMP_DIR ${CMAKE_BINARY_DIR}/googletest
    SOURCE_DIR ${CMAKE_BINARY_DIR}/googletest/src
    BINARY_DIR ${CMAKE_BINARY_DIR}/googletest/build
    URL https://github.com/google/googletest/archive/release-1.8.1.zip
    LOG_DOWNLOAD 1
    # EXCLUDE_FROM_ALL 1
    TEST_COMMAND    ""
    INSTALL_COMMAND ""
    PATCH_COMMAND ""
    # STEP_TARGET googletest
)

ExternalProject_Get_property(googletest SOURCE_DIR)
ExternalProject_Get_property(googletest BINARY_DIR)
add_library(gtest::gtest UNKNOWN IMPORTED)
set_target_properties(gtest::gtest PROPERTIES
    IMPORTED_LOCATION ${BINARY_DIR}/googlemock/gtest/libgtest.a
    INTERFACE_INCLUDE_DIRECTORIES ${SOURCE_DIR}/googletest/include
    INTERFACE_COMPILE_DEFINITIONS "GTEST_USE_OWN_TR1_TUPLE,__GLIBCXX__"
)

add_executable(test_gtest ${CMAKE_CURRENT_SOURCE_DIR}/test_gtest.cpp)
target_include_directories(test_gtest PRIVATE 
    $<TARGET_PROPERTY:gtest::gtest,INTERFACE_INCLUDE_DIRECTORIES>    
)
target_link_libraries(test_gtest PRIVATE
    $<TARGET_PROPERTY:gtest::gtest,IMPORTED_LOCATION>
)
add_test(NAME test_gtest COMMAND test_gtest)

# test for applesockets
add_executable(test_applesockets ${CMAKE_SOURCE_DIR}/tests/test_applesockets.cpp)
target_link_libraries(test_applesockets 
    PUBLIC 
    ${PROJECT_NAME}
    $<TARGET_PROPERTY:gtest::gtest,IMPORTED_LOCATION>
)

target_include_directories(test_applesockets 
    PUBLIC 
        ${CMAKE_SOURCE_DIR}/include
        $<TARGET_PROPERTY:gtest::gtest,INTERFACE_INCLUDE_DIRECTORIES>
    )

add_test(NAME test_applesockets COMMAND test_applesockets)
