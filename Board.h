//
// Created by rim on 10/17/22.
//

#ifndef PROJET_TETRAVEX_BOARD_H
#define PROJET_TETRAVEX_BOARD_H
#include <iostream>
#include "Card.h"


class Board {

public:
    int size;
    Card **grid;

    Board(int size);
    Board();
    void display();
    Card getPieceAt(int x, int y);
    void removePiece(int x, int y);
    bool placeCard(Card c, int x, int y);
    bool placable(Card card, int x, int y);


};


#endif //PROJET_TETRAVEX_BOARD_H
