cmake_minimum_required(VERSION 3.27)

set(NAME doc_logos)
project(${NAME} LANGUAGES CXX)

add_subdirectory(libs)

include(compiler_setup.cmake)

add_subdirectory(backend)

