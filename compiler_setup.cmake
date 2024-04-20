message("Setup compiler (23 cpp standart)..")

set(CMAKE_CXX_STANDARD 23)
message("Set cxx standart on 23")

set(FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS ${FLAGS})
message("Set cxx compiler flags on \"${FLAGS}\"")

message("Finish compiler setup.")
