#include <string>
#include <vector>
#include <stack>
#include <stdexcept>
#include "Board.hpp"
using namespace WarGame;

    //// OPERATORS ///
    Soldier *&Board::operator[](std::pair<int, int> location) {
        return board[location.first][location.second];
    }

    Soldier *Board::operator[](std::pair<int, int> location) const {
        return board[location.first][location.second];
    }
    /////////////////
    bool Board::has_soldiers(uint player_number) const{
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                Soldier* s = (*this)[{i, j}];
                if (s != nullptr && s->getPlayerNumber() == player_number)
                    return true;
            }
        }
        return false;
    }

    ////////////////
    void Board::move(uint player_number, std::pair<int,int> source, Board::MoveDIR direction) {
        int x1 = source.first;
        int y1 = source.second;
        Soldier* soldier = board[x1][y1];
        if(x1 < 0 || y1 < 0 || x1 >= board.size() || y1 >= board[0].size()) {
            throw std::invalid_argument("out of bound!");
        }
        if(soldier == nullptr) {
            throw std::invalid_argument("soldier isn't selected!");
        }
        if(soldier->getPlayerNumber() != player_number) {
            throw std::invalid_argument("not your player number!");
        }

        std::pair<int,int> target;
        switch(direction) {
            case Up :
                target= std::make_pair(x1+1, y1);
                break;

            case Down:
                target= std::make_pair(x1-1, y1);
                break;

            case Left:
                target= std::make_pair(x1, y1-1);
                break;

            case Right:
                target= std::make_pair(x1, y1+1);
                break;

            default:
                break;
        }

        int x2 = target.first;
        int y2 = target.second;
        if(x2 < 0 || y2 < 0 || x2 >= board.size() || y2 >= board[0].size()) {
            throw std::invalid_argument("out of bound!");
        }

        Soldier* s = (*this)[target];
        if(s != nullptr)
        {
            throw std::invalid_argument("There is already another soldier");
        }
        (*this)[source] = nullptr;
        (*this)[target] = soldier;
        soldier->action(board, target);
    }



