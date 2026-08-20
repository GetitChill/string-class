cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

project(MYSTRING)
find_package (Catch2 3 REQUIRED)
add_executable(string_output  /home/grant/Desktop/string/string_c.cpp)

add_executable(test_prac /home/grant/Desktop/string/test/tests.cpp )
target_link_libraries(test_prac PRIVATE Catch2::Catch2WithMain)

