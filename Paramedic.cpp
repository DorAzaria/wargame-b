#include "Paramedic.hpp"

void Paramedic::action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source) {
    int x1 = source.first;
    int y1 = source.second;
    Soldier* paramedic = board[x1][y1];
    for(int i = -1 ; i <= 1 ; i++) {
        for(int j = -1 ; j <= 1 ; j++) {
            if(board[x1 + i][y1 + j] != nullptr) {
                if(board[x1 + i][y1 + j]->getPlayerNumber() == paramedic->getPlayerNumber()) {
                    board[x1 + i][y1 + j]->setHP(board[x1 + i][y1 + j]->getMaxHP());
                }
            }
        }
    }
}
