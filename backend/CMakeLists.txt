set(BACKEND_NAME ${NAME}_backend)

set(BACKEND_SOURCES
    ./src/document.cpp)

add_library(${BACKEND_NAME} ${BACKEND_SOURCES})

target_include_directories(${BACKEND_NAME}
    PUBLIC inc/
    PRIVATE src/)

target_link_libraries(${BACKEND_NAME} PRIVATE zip)

add_subdirectory(examples)
