#pragma once
#include "FootSoldier.hpp"
using namespace std;
class FootCommander : public FootSoldier {
public:
    FootCommander(uint playerNumber, int hp = 150, int maxHP = 150, int damage = 20,string type = "FC") : FootSoldier(playerNumber, hp, maxHP, damage,type){}
    ~FootCommander(){}
    void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source);
};