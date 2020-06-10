#include <iostream>
#include <vector>
#include "FootSoldier.hpp"
using namespace std;

void FootSoldier::action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source) {
    int x1 = source.first;
    int y1 = source.second;
    int x2 = -1;
    int y2 = -1;
    Soldier* footSoldier = board[x1][y1];
    Soldier* enemy = nullptr;
    double min = 1000.0;

    for(int i = 0 ; i < board.size() ; ++i) {
        for(int j = 0 ; j < board[i].size() ; ++j) {
            if(board[i][j] != nullptr) {
                if(board[i][j]->getPlayerNumber() != footSoldier->getPlayerNumber()) {
                    double distance = getDistance(x1,y1,i,j);
                    if(min > distance){
                        min = distance;
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
    }
    if(x2 != -1 && y2 != -1) {
        enemy = board[x2][y2];
        enemy->setHP(enemy->getHP() - footSoldier->getDamage());
        if(enemy->isDead()) {
            board[x2][y2] = nullptr;
        }
    }
}
