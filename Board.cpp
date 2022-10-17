//
// Created by rim on 10/17/22.
//
#include "Board.h"
#include <iostream>
#include "Card.h"
#include <vector>
#include <tuple>

Board::Board(){
    this->size = 3;
    this->grid = new Card *[this->size];
    for(int i = 0; i < this->size; i++){
        this->grid[i] = new Card [this->size];
        for(int j = 0; j < this->size; j++){
            this->grid[i][j] = Card();
        }
    }
    //std::cout << "CONSTRUCTOR FINISHED " << std::endl;

}

Board::Board(int size){

    this->size = size;
    this->grid = new Card *[this->size];
    for(int i = 0; i < this->size; i++){
        this->grid[i] = new Card [this->size];
        for(int j = 0; j < this->size; j++){
            //std::cout << i << "," << j << std::endl;

            this->grid[i][j] = Card();
            //this->grid[i][j].display();
        }
    }
    //std::cout << "CONSTRUCTOR FINISHED " << std::endl;

}

Card Board::getCardAt(int x, int y){
    return this->grid[x][y];
}

void Board::removeCard(int x, int y){
    this->grid[x][y] = Card();

}


bool Board::placable(Card card, int x, int y){
    //if(x < 0 || y < 0 || x > size-1 || y > size-1) return false;
    //if(grid[x][y].right != -1) return false;

        if(x + 1 <= size-1){
            if(grid[x+1][y].right != -1){
                if(grid[x+1][y].top != card.bottom) return false;
            }
        }
        if(y + 1 <= size-1){
            if(grid[x][y+1].right != -1){
                if(grid[x][y+1].left != card.right) return false;
            }
        }
        if(x - 1 >= 0){
            if(grid[x-1][y].right != -1){
                if(grid[x-1][y].bottom != card.top) return false;
            }
        }
        if(y - 1 >= 0){
            if(grid[x][y-1].right != -1){
                if(grid[x][y-1].right != card.left) return false;
            }
        }


    return true;
}

bool Board::placeCard(Card card, int x, int y){
    if(placable(card, x, y)){
        card.setPlaced(true);
        grid[x][y] = card;
        return true;
    }
    //cout << "Move impossible"<<endl;
    return false;
}


void Board::display() {
    for(int i = 0; i < this->size; i++) {
        for(int j = 0; j < this->size; j++)
            std::cout << ".--" << getCardAt(i, j).top << "--." ;
        std::cout << std::endl;
        for(int j = 0; j < this->size; j++)
            std::cout << "|" << getCardAt(i, j).left << "   " << getCardAt(i, j).right << "|";
        std::cout << std::endl;
        for(int j = 0; j < this->size; j++)
            std::cout << ".__" << getCardAt(i, j).bottom << "__." ;
        std::cout << std::endl;
        std::cout << "---------------------" << std::endl;
    }
}
