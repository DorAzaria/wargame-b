
#include "Sniper.hpp"

void Sniper::action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source) {
    int x1 = source.first;
    int y1 = source.second;
    int x2 = -1;
    int y2 = -1;
    Soldier* sniper = board[x1][y1];
    Soldier* enemy = nullptr;
    int max = 0;

    for(int i = 0 ; i < board.size() ; i++) {
        for(int j = 0 ; j < board[i].size() ; j++) {
            if(board[i][j] != nullptr) {
                if(max < board[i][j]->getHP() && sniper->getPlayerNumber() != board[i][j]->getPlayerNumber()){
                    max = board[i][j]->getHP();
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }

    if(x2 != -1 && y2 != -1) {
        enemy = board[x2][y2];
        enemy->setHP(enemy->getHP() - sniper->getDamage());
        if(enemy->isDead()) {
            board[x2][y2] = nullptr;
        }
    }
}
