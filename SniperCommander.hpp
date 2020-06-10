#pragma once
#include "Sniper.hpp"
using namespace std;
class SniperCommander : public Sniper {
    public:
        SniperCommander(uint playerNumber, int hp = 120, int maxHP = 120, int damage = 100,string type = "SC") : Sniper(playerNumber,hp,maxHP,damage,type){}
        ~SniperCommander(){}
        void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source);
};
