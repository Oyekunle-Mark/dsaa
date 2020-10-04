cmake_minimum_required(VERSION 3.17)
project(dsaa)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall")

add_executable(dsaa main.cpp lists/Vector.cpp lists/Vector.h lists/List.cpp lists/List.h leetcode/MaxConsecutiveOnes.cpp leetcode/NumbersWithEvenDigits.cpp)
