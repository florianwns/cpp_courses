cmake_minimum_required(VERSION 3.17)
project(cpp_courses)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER_VERSION 11)
#set(CMAKE_C_COMPILER /usr/bin/gcc)
#set(CMAKE_CXX_COMPILER /usr/bin/g++)


# from https://docs.conan.io/1/integrations/ide/clion.html
if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else ()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif ()

add_subdirectory("000_epfl_introduction_to_programming")
add_subdirectory("001_opencv_experiments")
add_subdirectory("002_boost_experiments")
add_subdirectory("003_vrac")
