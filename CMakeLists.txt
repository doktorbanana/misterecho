cmake_minimum_required(VERSION 3.22)

project(MisterEchoStarter)

set(CMAKE_CXX_STANDARD 23)

set(LIB_DIR "${CMAKE_SOURCE_DIR}/libs")
include(cmake/CPM.cmake)

CPMAddPackage(
  NAME JUCE
  GITHUB_REPOSITORY juce-framework/JUCE
  GIT_TAG 8.0.8
  VERSION 8.0.8
  SOURCE_DIR "${LIB_DIR}/juce"
)
