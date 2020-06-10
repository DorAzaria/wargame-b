#include "ParamedicCommander.hpp"

void ParamedicCommander::action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source){
    int x1 = source.first;
    int y1 = source.second;
    Soldier* paramedicCommander = board[x1][y1];
    std::stack<std::pair<int,int>> myPlatoon;

    for(int i = -1; i <= 1 ; i++) {
        for(int j = -1; j <= 1 ; j++) {
            if(board[x1 + i][y1 + j] != nullptr) {
                if(board[x1 + i][y1 + j]->getPlayerNumber() == paramedicCommander->getPlayerNumber()) {
                    board[x1 + i][y1 + j]->setHP(board[x1 + i][y1 + j]->getMaxHP());
                }
            }
        }
    }
    for(int i = 0 ; i < board.size() ; i++) {
        for(int j = 0 ; j < board[i].size() ; j++) {
            if(board[i][j] != nullptr) {
                if(board[i][j]->getPlayerNumber() == paramedicCommander->getPlayerNumber()) {
                    if(board[i][j]->getType() == "P"){
                        myPlatoon.push({i,j});
                    }
                }
            }
        }
    }
    while(!myPlatoon.empty()){
        std::pair<int,int> current = myPlatoon.top();
        board[current.first][current.second]->action(board,current);
        myPlatoon.pop();
    }
};
