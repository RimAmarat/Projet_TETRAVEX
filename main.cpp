//
// Created by rim on 10/17/22.
//
#include <iostream>
#include "Game.h"
#include "Solver.h"
#include <fstream>
#include <string>
class Game; // forward declaration

int main(){

    Game game = Game("./entree5.txt");
    Solver solver = Solver(game);
    solver.parallelBacktracking(25);


//game.displayBoard();
    return 0;
}
