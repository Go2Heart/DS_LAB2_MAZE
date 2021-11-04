cmake_minimum_required(VERSION 3.16)
project (Test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -DTEST) 
add_executable(Test
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
