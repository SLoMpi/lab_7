cmake_minimum_required(VERSION 3.29)
project(laba_7_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(laba_7_2 main.cpp
        loadFromFile.cpp
        saveToFile.cpp
        header.h
        scoreToString.cpp
)
