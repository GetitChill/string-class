cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

project(MYSTRING)
find_package (Catch2 3 REQUIRED)
add_library(string_output_array  /home/grant/Desktop/string/std_array_imp/arrayString.cpp)
add_library(string_output_array_h  /home/grant/Desktop/string/heap_implementation/heapstring.cpp)

add_executable(test_prac_array /home/grant/Desktop/string/test/tests.cpp )
add_executable(test_prac_heap /home/grant/Desktop/string/test/tests.cpp )

target_link_libraries(test_prac_array PRIVATE string_output_array Catch2::Catch2WithMain)
target_link_libraries(test_prac_heap PRIVATE string_output_array_h Catch2::Catch2WithMain)

