cmake_minimum_required(VERSION 3.8)

project(box2d LANGUAGES CXX)

set(CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo" CACHE STRING "" FORCE)

add_subdirectory(src)

option(BUILD_TESTS "Build the Box2D unit tests" ON)
option(BUILD_SAMPLES "Build the Box2D samples" ON)


