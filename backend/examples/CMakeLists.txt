option(BACKEND_EXAMPLES off)

if(BACKEND_EXAMPLES)
    add_executable(unzip_example unzip_example/main.cpp)
    target_link_libraries(unzip_example zip pugixml)
endif()
