//
// Created by rim on 10/30/22.
//

#ifndef PROJET_TETRAVEX_CARD_H
#define PROJET_TETRAVEX_CARD_H

#include <iostream>
#include <vector>
#include <string>

class Card{
public:
    int left;
    int top;
    int right;
    int bottom;

    bool placed = false;

    Card(std::vector<int> vect);

    Card();

    void display();

    bool isPlaced();

    void setPlaced(bool value);

    Card CardCopy();
};

#endif //PROJET_TETRAVEX_CARD_H

