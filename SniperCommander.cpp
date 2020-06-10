#include "SniperCommander.hpp"

void SniperCommander::action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source) {
    int x1 = source.first;
    int y1 = source.second;
    int x2 = -1;
    int y2 = -1;
    int max = 0;
    Soldier* sniperCommander = board[x1][y1];
    Soldier* enemy = nullptr;
    std::stack<std::pair<int,int>> myPlatoon;

    for(int i = 0 ; i< board.size() ; i++) {
        for(int j = 0 ; j < board[i].size(); j++) {
            if(board[i][j] != nullptr) {
                if(sniperCommander->getPlayerNumber() != board[i][j]->getPlayerNumber()) {
                    if(max < board[i][j]->getHP()) {
                        max = board[i][j]->getHP();
                        x2 = i;
                        y2 = j;
                    }
                    else {
                        if(board[i][j]->getType() == "S"){
                            myPlatoon.push({i,j});
                        }
                    }
                }
            }
        }
    }
    if(x2 != -1 && y2 != -1) {
        enemy = board[x2][y2];
        enemy->setHP(enemy->getHP() - sniperCommander->getDamage());
        if(enemy->isDead()) {
            board[x2][y2] = nullptr;
        }
    }
    while(!myPlatoon.empty()){
        std::pair<int,int> current = myPlatoon.top();
        board[current.first][current.second]->action(board,current);
        myPlatoon.pop();
    }
}
