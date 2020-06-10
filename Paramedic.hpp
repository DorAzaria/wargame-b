#pragma once
#include "Soldier.hpp"
using namespace std;

class Paramedic : public Soldier {
    public:
        Paramedic(uint playerNumber, int hp = 100, int maxHP = 100, int damage = 0, string type = "P"):Soldier(playerNumber,hp,maxHP,damage,type){}
        virtual~Paramedic(){}
        virtual void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source);
    void healAround(std::vector<std::vector<Soldier*>> &board,int x1,int y1){
        for(int i = -1 ; i <= 1 ; i++) {
            for(int j = -1 ; j <= 1 ; j++) {
                if(board[x1 + i][y1 + j] != nullptr) {
                    if(board[x1 + i][y1 + j]->getPlayerNumber() == board[x1][y1]->getPlayerNumber()) {
                        board[x1 + i][y1 + j]->setHP(board[x1 + i][y1 + j]->getMaxHP());
                    }
                }
            }
        }
    }
};


