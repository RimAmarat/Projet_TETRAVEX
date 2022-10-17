//
// Created by rim on 10/17/22.
//
#include "Game.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

#include <chrono>
#include <ctime>
Game::Game() {
    this->size = 3;
    this->board = Board(this->size);
    this->cards = {};
}

Game::Game(std::string filename){


    std::string line;
    std::ifstream myfile(filename);

    // Game SIZE
    if (getline (myfile,line))
        this->size =  stoi(line);

    std::cout << "* SIZE = " << this->size << std::endl;

    // Initialize the board
    this->board = Board(this->size);

    // Get all cards from entry file
    std::vector<int> vect;

    while ( getline (myfile,line) )
    {
        std::stringstream ss (line);   /* make stringstream from s */
        int f;
        while ((ss >> f))  {
            vect.push_back (f);
        }         /* read ints from ss into f */

        this->cards.push_back(Card(vect));
        vect.clear();
    }
        myfile.close();

}

void Game::addPiece(Card p){
    if(cards.size() < size^2) this->cards.push_back(p);
}

void Game::removePiece(int x, int y){
    Card card = board.getPieceAt(x, y);
    if(card.bottom != -1){
        board.removePiece(x, y);
        card.setPlaced(false);
        //std::cout << "Before adding this card" ;
        //card.display();
        //displayCards();
        cards.push_back(card);
        //std::cout << "After adding a card" << std::endl;
        //displayCards();
    }
}

void Game::displayBoard(){
    board.display();
}

void Game::displayCards(){
    std::cout << "Game::displayCards()" << std::endl;
    for(int i = 0; i < this->size * this->size; i++)
        std::cout << ".--" << cards[i].top << "--." ;
        std::cout << std::endl;
    for(int i = 0; i < this->size * this->size; i++)
        std::cout << "|" << cards[i].left << "   " << cards[i].right << "|";
        std::cout << std::endl;
    for(int i = 0; i < this->size * this->size; i++)
        std::cout << ".__" << cards[i].bottom << "__." ;
        std::cout << std::endl;
}

bool Game::move(Card c, int x, int y){
    if(this->board.placeCard(c, x, y)){
        this->removeFromCards(c);
        return true;
    }
    return false;
}

bool Game::cardsEmpty(){
    return cards.empty();
}

void Game::removeFromCards(Card card){
    //std::cout << "Before removing this card" ;
    //card.display();
    //displayCards();

    for(int i=cards.size()-1; i>-1; i--)
        if((card.bottom == cards[i].bottom) && (card.top == cards[i].top) && (card.left == cards[i].left) && (card.right == cards[i].right))
            this->cards.erase(cards.begin() + i);


    //board.removePiece(x, y);
    //card.setPlaced(false);

    //std::cout << "After removing a card" << std::endl;
    //displayCards();
}

Game Game::copy(){
    Game copy = Game();
    copy.size = this->size;
    copy.board = Board(this->size);
    for (int i = 0; i< this->cards.size(); i++)
    {
        copy.cards.push_back(this->cards[i].CardCopy());
    }
    return copy;
}


