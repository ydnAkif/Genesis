cmake_minimum_required(VERSION 4.2)

project(Genesis

        VERSION 0.1.0

        DESCRIPTION "A minimal educational Transformer implementation from scratch in C++20"

        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/main.cpp)

set(PROJECT_HEADERS
        ${PROJECT_INCLUDE_DIR}/genesis/core/Version.hpp)

add_library(genesis_core src/text/Tokenizer.cpp)

target_include_directories(genesis_core PUBLIC ${PROJECT_INCLUDE_DIR})


add_executable(genesis_app ${PROJECT_SOURCES})

target_link_libraries(genesis_app PRIVATE genesis_core)