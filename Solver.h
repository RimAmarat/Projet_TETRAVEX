//
// Created by rim on 10/17/22.
//

#ifndef PROJET_TETRAVEX_SOLVER_H
#define PROJET_TETRAVEX_SOLVER_H
#include "Game.h"
#include "Board.h"
#include "ThreadPool.h"
#include <chrono>

class Solver {
    Board board;
    int size;
    Game game;
    ThreadPool pool;
    int currentCard;

public:
    std::chrono::high_resolution_clock::time_point start;
    Solver(Game game);


    void sequentialBacktracking();
    void recursiveBruteforce(int x, int y);
    void threadCards(int thIndex);
    void recursiveBruteforceP(int x, int y, Game &game);
    void parallelBacktracking(int num_threads);
    void makeThread(Game game);
    void sequentialBacktrackingP();

    //void sequentialBacktracking(Game game);
    //void recursiveBruteforce(Game game, int x, int y);
};


#endif //PROJET_TETRAVEX_SOLVER_H
