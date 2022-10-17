//
// Created by rim on 10/17/22.
//

#include "Solver.h"
#include "Game.h"
#include "ThreadPool.h"
#include <chrono>
#include <ctime>
#include <chrono>

Solver::Solver(Game game) {
    this->game = game;
    this->board = game.board;
    this->size = game.size;
    this->currentCard = 0;
}

void Solver::sequentialBacktracking(){

    start = std::chrono::high_resolution_clock::now();
    recursiveBruteforce(0, 0);
}
void Solver::recursiveBruteforce(int x, int y){
    //std::cout << "Cards " << std::endl;
    //game.displayCards();
    //std::cout << "Board" << std::endl;
    //game.displayBoard();
    if(game.cards.empty()){
        std::cout << "resolved in " << std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start).count() << "s"<<std::endl;;
        game.displayBoard();
        exit(0);
        return;
    }
    for(int i=0; i<game.cards.size(); i++){
        Card p = game.cards[i];
        if(!p.isPlaced()){
            if(game.move(p, x, y)){
                int nextx = x;
                int nexty = y+1;
                if(nexty == game.size){
                    nexty = 0;
                    nextx ++;
                    if(nextx == game.size)
                        nextx = 0;
                }
                recursiveBruteforce(nextx, nexty);
                game.removePiece(x, y);
            }
        }
    }
}

void Solver::recursiveBruteforceP(int x, int y, Game &gameCopy){

    if(gameCopy.cards.empty()){
        std::cout << "resolved in " << std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start).count() << "s" <<std::endl;;
        gameCopy.displayBoard();
        pool.killThreads();
        return;
    }
    for(int i=0; i<gameCopy.cards.size(); i++){
        Card p = gameCopy.cards[i];
        if(!p.isPlaced()){
            if(gameCopy.move(p, x, y)){
                int nextx = x;
                int nexty = y+1;
                if(y == gameCopy.size-1){
                    nextx ++;
                    nexty = 0;
                }
                recursiveBruteforceP(nextx, nexty, gameCopy);
                gameCopy.removePiece(x, y);
            }
        }
    }
}


void Solver::threadCards(int numThreads){

    /*
    pool.m->lock();
    std::cout << "game copy card stock at thread " << thIndex << std::endl;
    gameCopy.displayCards();
    pool.m->unlock();
    */
    while(currentCard < numThreads)
    {
        pool.addThread(new std::thread(&Solver::makeThread, this, this->game));
        pool.m->lock();
        currentCard++;
        std::cout << "current card " << currentCard << std::endl;
        pool.m->unlock();
    }

}
void Solver::makeThread(Game game){
    Game gameCopy = game.copy();
    gameCopy.move(gameCopy.cards[currentCard], 0, 0);
    recursiveBruteforceP(0, 1, gameCopy);
}

void Solver::parallelBacktracking(int num_threads){

    start = std::chrono::high_resolution_clock::now();
    threadCards(num_threads);
    pool.joinThreads();

}

