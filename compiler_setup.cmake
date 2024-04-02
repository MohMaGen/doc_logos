function(setup_compiler)
    message("Setup compiler (23 cpp standart)..")

    set(CMAKE_CXX_STANDART 23)
    message("Set cxx standart on 23")

    set(FLAGS "-Wall -Wextra")
    set(CMAKE_CXX_COMPILER_FLAG ${FLAGS})
    message("Set cxx compiler flags on ${FLAGS}")
    
    message("Finish compiler setup.")
endfunction()