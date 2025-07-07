cmake_minimum_required(VERSION 3.22)

project(MisterEchoTest)


add_executable(${PROJECT_NAME}
    src/AudioProcessorTest.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/application/include
        ${JUCE_SOURCE_DIR}/modules

)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        MisterEcho
        Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)

include(CTest)
include(Catch)
catch_discover_tests(MisterEchoTest)