cmake_minimum_required(VERSION 3.23)
project(Projet_TETRAVEX)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Projet_TETRAVEX
        Backtracking.cpp
        Backtracking.h
        Board.cpp
        Board.h
        Card.cpp
        main.cpp
        SequentialBacktracking.cpp
        SequentialBacktracking.h
        Solver.cpp
        Solver.h
        Game.cpp
        Game.h
        ThreadParallelismBacktracking.cpp
        ThreadParallelismBacktracking.h
        ThreadPoolBacktracking.cpp
        ThreadPoolBacktracking.h ThreadPool.cpp ThreadPool.h)
