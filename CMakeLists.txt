cmake_minimum_required(VERSION 3.12)

set(GENICAM_VERSION_MAJOR 3)
set(GENICAM_VERSION_MINOR 0)
set(GENICAM_VERSION_PATCH 0)
set(GENICAM_VERSION_TWEAK 0)

set(GENICAM_VERSION 
"${GENICAM_VERSION_MAJOR}.${GENICAM_VERSION_MINOR}.${GENICAM_VERSION_PATCH}.${GENICAM_VERSION_TWEAK}")

cmake_policy(SET CMP0048 NEW)

project(genicam 
    VERSION ${GENICAM_VERSION} 
    DESCRIPTION "Genicam framework implementation for mac" 
    LANGUAGES CXX )

set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 14)
set(BUILD_SHARED_LIBS ON)
set(BUILD_UNIT_TESTS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include(GNUInstallDirs)
include(ExternalProject)

string(TOLOWER ${CMAKE_BUILD_TYPE} _buildtype)

if (_buildtype STREQUAL debug )
    message(STATUS "Building with debug info.")
    set(BUILD_UNIT_TESTS ON)
endif()

# add and compile thirdparty libraries
# add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty)
# generates a versioning file for genicamversion
configure_file(
    ${CMAKE_SOURCE_DIR}/include/genicam/_GenICamVersion.hpp.in 
    ${CMAKE_SOURCE_DIR}/include/genicam/_GenICamVersion.hpp
    )

add_library(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/AppleSockets.cpp)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/GigeV>
)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)

add_executable(${PROJECT_NAME}_run tools/Run.cpp)
target_include_directories(${PROJECT_NAME}_run PRIVATE 
$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>)

if (BUILD_UNIT_TESTS)
    message(STATUS "building unit tests.")
    enable_testing()
    add_subdirectory(tests)
endif()