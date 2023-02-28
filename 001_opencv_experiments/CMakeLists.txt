message("-- Add OpenCV Exerimentations")

add_executable(001_000_hello_world 000_hello_world/main.cpp)
target_link_libraries(001_000_hello_world ${CONAN_LIBS})

add_executable(001_001_capture_frame 001_capture_frame/main.cpp)
target_link_libraries(001_001_capture_frame ${CONAN_LIBS})

add_executable(001_002_processings 002_processings/main.cpp)
target_link_libraries(001_002_processings ${CONAN_LIBS})
