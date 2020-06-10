#include "Paramedic.hpp"

void Paramedic::action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source) {
    int x1 = source.first;
    int y1 = source.second;
    healAround(board,x1,y1);
}
