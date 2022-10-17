//
// Created by rim on 10/17/22.
//
#include "Card.h"
#include <iostream>
#include <vector>
#include <string>

Card::Card(std::vector<int> vect) {
    this->left = vect[0];
    this->top = vect[1];
    this->right = vect[2];
    this->bottom = vect[3];}

Card::Card(){
        this->left = -1;
        this->top = -1;
        this->right = -1;
        this->bottom = -1;
    }

void Card::display(){
    //std::cout << " _______" << std::endl;
    std::cout << ".---" << this->top << "---." << std::endl;
    std::cout << "<" << this->left << "     " << this->right << ">" << std::endl;
    std::cout << ".___" << this->bottom << "___." << std::endl;
    //std::cout << " -------" << std::endl;
    }

bool Card::isPlaced(){
    return placed;
}

void Card::setPlaced(bool value){
    this->placed = value;
}

Card Card::CardCopy(){
    return Card({left, top, right, bottom});
}