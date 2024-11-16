cmake_minimum_required(VERSION 3.29)
project(laba_7_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(laba_7_1 main.cpp
        header.h
        saveToFile.cpp
        loadFromFile.cpp
        book.h)
