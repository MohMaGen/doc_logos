cmake_minimum_required(VERSION 3.27)

set(NAME doc_logos)
project(${NAME} LANGUAGES CXX)

include(compiler_setup.cmake)
setup_compiler()

add_subdirectory(backend)