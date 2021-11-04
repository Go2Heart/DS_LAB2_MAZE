cmake_minimum_required(VERSION 3.16)
project (lab_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_2
        Array.h
        BfsNode.cpp
        BfsNode.h
        BfsSolver.cpp
        BfsSolver.h
        DfsNode.cpp
        DfsNode.h
        DfsSolver.cpp
        DfsSolver.h
        main.cpp
        Queue.h
        Stack.h)
