//
// Created by rim on 10/17/22.
//
#ifndef PROJET_TETRAVEX_GAME_H
#define PROJET_TETRAVEX_GAME_H
#include <string>
#include <fstream>
#include <iostream>

#include <iostream>
#include "Board.h"

class Game {
public:
    int size = 3;
    Board board;
    std::vector<Card> cards;

    Game(std::string filename);
    Game();

    void addPiece(Card p);
    void removePiece(int x, int y);
    bool cardsEmpty();
    Game copy();
    void removeFromCards(Card card);

    void displayResults();

    void displayBoard();

    void displayCards();

    bool move(Card c, int x, int y);

    //void sequentialBacktracking(Game game);

    //void recursiveBruteforce(Game game, int x, int y);

};
#endif //PROJET_TETRAVEX_GAME_H
