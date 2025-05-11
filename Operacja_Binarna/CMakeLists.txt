cmake_minimum_required(VERSION 3.30)
project(Operacja_Binarna)

set(CMAKE_CXX_STANDARD 20)

add_executable(Operacja_Binarna
        main.cpp
        calculate.hpp
        calculate.tpp
)

add_executable(Test_Operacja_Binarna
        test.cpp
        calculate.hpp
        calculate.tpp
)
