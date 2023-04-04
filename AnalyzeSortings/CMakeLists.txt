cmake_minimum_required(VERSION 3.21)
project(AnalyzeSortings)

set(CMAKE_CXX_STANDARD 17)

add_executable(AnalyzeSortings main.cpp sorting_time.h sorting_time.cpp ArrayTime.cpp ArrayTime.h sorting_operations.cpp sorting_operations.h SortingOperations.cpp SortingOperations.h ArrayOperations.cpp ArrayOperations.h)
