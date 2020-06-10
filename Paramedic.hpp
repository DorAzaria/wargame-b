#pragma once
#include "Soldier.hpp"
using namespace std;

class Paramedic : public Soldier {
    public:
        Paramedic(uint playerNumber, int hp = 100, int maxHP = 100, int damage = 0, string type = "P"):Soldier(playerNumber,hp,maxHP,damage,type){}
        virtual~Paramedic(){}
        virtual void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source);
};


