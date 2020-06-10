#pragma once
#include "Paramedic.hpp"
using namespace std;
class ParamedicCommander : public Paramedic {
    public:
        ParamedicCommander(uint playerNumber, int hp = 200, int maxHP = 200, int damage = 0, string type = "PC") : Paramedic(playerNumber,hp,maxHP,damage,type){}
        ~ParamedicCommander(){}
        void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source);
};


