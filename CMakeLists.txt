# Set CMAKE version
cmake_minimum_required(VERSION 3.22.1)

# Project config
project(vector_math
    VERSION 0.1.0
    DESCRIPTION "A mathematical vector library"
    LANGUAGES CXX)

# Set C++ options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Add subdirectories
add_subdirectory(include)

# Option to turn examples and testing on and off
option(BUILD_TESTS "" on)
option(BUILD_EXAMPLES "" on)

if(BUILD_TESTS)
    message(STATUS "Building tests...")
    add_subdirectory(tests)
endif()

if(BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(examples)
endif()



