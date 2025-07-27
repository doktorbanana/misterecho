cmake_minimum_required(VERSION 3.22)

project(MisterEchoStarter)

set(CMAKE_CXX_STANDARD 23)
set(PROJECT_NAME "MisterEcho")
set(PRODUCT_NAME "MisterEcho")
set(BUNDLE_ID "com.pemaal.misterecho")
set(COMPANY_NAME "Pemaal")
set(CURRENT_VERSION "0.1.0")
set(MAJOR_VERSION 0)
set(MINOR_VERSION 1)
set(PATCH_LEVEL 0)
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
    # Disable warnings-as-errors for juce_vst3_helper
    set_target_properties(juce_vst3_helper PROPERTIES COMPILE_OPTIONS "/WX-")
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

add_subdirectory(application)
add_subdirectory(tests)