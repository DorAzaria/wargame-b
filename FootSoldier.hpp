#pragma once
#include <iostream>
#include "Soldier.hpp"
using namespace std;

class FootSoldier : public Soldier {
public:
    FootSoldier(uint playerNumber, int hp = 100 , int maxHP = 100, int damage = 10,string type = "FS") : Soldier(playerNumber, hp, maxHP, damage,type){}
    virtual ~FootSoldier(){}
    virtual void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source);
    double getDistance(int x1, int y1, int x2, int y2) {
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));}
};


