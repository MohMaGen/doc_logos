option(BACKEND_EXAMPLES off)

if(BACKEND_EXAMPLES)
    add_executable(document_example document_example/main.cpp)
    target_link_libraries(document_example ${BACKEND_NAME}})
endif()