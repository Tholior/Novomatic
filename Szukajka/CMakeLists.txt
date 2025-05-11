cmake_minimum_required(VERSION 3.30)
project(Szukajka)

set(CMAKE_CXX_STANDARD 20)

add_executable(Szukajka
        main.cpp
        searchengine.cpp
        searchengine.hpp
)

add_executable(TestSzukajka
        test.cpp
        searchengine.cpp
        searchengine.hpp
)