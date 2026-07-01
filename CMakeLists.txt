cmake_minimum_required(VERSION 4.2)

project(Genesis
        VERSION 0.1.0
        DESCRIPTION "A minimal educational Transformer implementation from scratch in C++20"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(genesis_core
        src/text/Tokenizer.cpp
        src/text/Vocabulary.cpp)

target_include_directories(genesis_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(genesis_demo
        apps/genesis_demo.cpp)

target_link_libraries(genesis_demo
        PRIVATE
        genesis_core)

enable_testing()

add_executable(tokenizer_tests
        tests/TokenizerTests.cpp)

target_link_libraries(tokenizer_tests
        PRIVATE
        genesis_core)

add_test(NAME tokenizer_tests COMMAND tokenizer_tests)

add_executable(vocabulary_tests
        tests/VocabularyTests.cpp)

target_link_libraries(vocabulary_tests
        PRIVATE
        genesis_core)

add_test(NAME vocabulary_tests COMMAND vocabulary_tests)

add_executable(text_pipeline_tests
        tests/TextPipelineTests.cpp)

target_link_libraries(text_pipeline_tests
        PRIVATE
        genesis_core)

add_test(NAME text_pipeline_tests COMMAND text_pipeline_tests)