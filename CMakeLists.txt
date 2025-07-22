cmake_minimum_required(VERSION 3.22)

project(MisterEchoStarter)

set(CMAKE_CXX_STANDARD 23)

set(PROJECT_NAME "MisterEcho")

set(LIB_DIR "${CMAKE_SOURCE_DIR}/libs")
include(cmake/CPM.cmake)
include(cmake/GithubENV.cmake)

CPMAddPackage(
  NAME JUCE
  GITHUB_REPOSITORY juce-framework/JUCE
  GIT_TAG 8.0.8
  VERSION 8.0.8
  SOURCE_DIR "${LIB_DIR}/juce"
)

CPMAddPackage(
  NAME Catch2
  GITHUB_REPOSITORY catchorg/Catch2
  GIT_TAG v3.8.1
  VERSION 3.8.1
  SOURCE_DIR "${LIB_DIR}/catch2"
)


if(MSVC)
    add_compile_options(/Wall /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

add_subdirectory(application)
add_subdirectory(tests)