message("-- Add Boost Experiments")

add_executable(002_000_hello_world 000_hello_world/main.cpp)
target_link_libraries(002_000_hello_world ${CONAN_LIBS})
