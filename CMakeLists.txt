cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

project(MYSTRING)
find_package (Catch2 3 REQUIRED)


# command in CMake is used to define a library target from specified source files, creating a reusable collection of compiled code that can be linked into executables or other libraries.

add_library(string_output_array  /home/grant/Desktop/string/std_array_imp/arrayString.cpp)
add_library(string_output_array_h  /home/grant/Desktop/string/heap_implementation/heapstring.cpp)

#add_executable() is a core CMake command used to define an executable binary (a runnable program) as a build target
add_executable(test_prac_array /home/grant/Desktop/string/test/tests.cpp )
add_executable(test_prac_heap /home/grant/Desktop/string/test/tests.cpp )



#is a command used to add preprocessor definitions (macros) to a specific target, such as an executable or a librar
target_compile_definitions(test_prac_heap PRIVATE USE_HEAP)

#target_link_libraries is a core CMake command used to specify that a target (such as an executable or a library) depends on other libraries
target_link_libraries(test_prac_array PRIVATE string_output_array Catch2::Catch2WithMain)
target_link_libraries(test_prac_heap PRIVATE string_output_array_h Catch2::Catch2WithMain)

