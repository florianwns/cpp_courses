find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

message("-- Add OpenCV Exerimentations")
message("OpenCV_INCLUDE_DIRS : ${OpenCV_INCLUDE_DIRS}")
message("OpenCV_LIBS : ${OpenCV_LIBS}")

add_executable(001_000_hello_world 000_hello_world/main.cpp)
target_link_libraries(001_000_hello_world ${OpenCV_LIBS})
