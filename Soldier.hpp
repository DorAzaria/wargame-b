#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;
class Soldier {
protected:
    uint playerNumber;
    int hp;
    int damage;
    int maxHP;
    std::string type;
public :
    Soldier(uint mPlayerNumber, int mHp, int mMaxHP, int mDamage,string type) : playerNumber(mPlayerNumber), hp(mHp), maxHP(mMaxHP), damage(mDamage), type(type){}
    virtual ~Soldier(){}
    virtual void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source) = 0;

    uint getPlayerNumber() {
        return playerNumber;}
    int getHP() {
        return hp;}
    int getMaxHP() {
        return maxHP;}
    int getDamage() {
        return damage;}
    std::string getType() {
        return type;}
    void setHP(int newHP){
        hp = newHP;}
    bool isDead() {
        if(hp <= 0)
            return true;
        return false;}

};
