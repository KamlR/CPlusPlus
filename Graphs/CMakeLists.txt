cmake_minimum_required(VERSION 3.21)
project(Graphs)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graphs main.cpp HouseOfGraphs.cpp HouseOfGraphs.h ConsoleInput.cpp ConsoleInput.h FileInput.cpp FileInput.h)
