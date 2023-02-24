message("-- Add OpenCV Exerimentations")

add_executable(001_000_hello_world 000_hello_world/main.cpp)
target_link_libraries(001_000_hello_world ${CONAN_LIBS})
