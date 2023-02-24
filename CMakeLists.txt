cmake_minimum_required(VERSION 3.17)
project(cpp_courses)
set(CMAKE_CXX_STANDARD 20)

# from https://docs.conan.io/1/integrations/ide/clion.html
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

add_subdirectory("000_initiation_programmation")
add_subdirectory("001_opencv_experiments")
add_subdirectory("002_boost_experiments")
