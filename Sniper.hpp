#pragma once
#include "Soldier.hpp"
using namespace std;
class Sniper: public Soldier{
public:
    Sniper(uint playerNumber,int hp = 100, int maxHP = 100, int damage = 50,string type = "S") : Soldier(playerNumber,hp,maxHP,damage,type){}
    virtual~Sniper(){}
    virtual void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source);
};


