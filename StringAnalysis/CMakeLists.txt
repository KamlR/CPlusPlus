cmake_minimum_required(VERSION 3.21)
project(StringAnalysis)

set(CMAKE_CXX_STANDARD 14)

add_executable(StringAnalysis main.cpp DataGenerator.cpp DataGenerator.h PatternSearch.cpp PatternSearch.h)
