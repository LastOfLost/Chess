#pragma once
#include "Figure.h"
#include "Board.h"

class Pawn : public Figure
{
public:

    vector<vector<MATRIX_INTENTIFICATOR>>& MatrixVarAttack(Board& board) const override {

        if (board.GetSizeY() == 0 && board.GetSizeX() == 0) return;

        vector<vector<MATRIX_INTENTIFICATOR>> result(board.GetSizeY(), vector<MATRIX_INTENTIFICATOR>(board.GetSizeX()));

        result[positY][positX] = MATRIX_INTENTIFICATOR::THIS_FIGURE;
        auto matrixBoard = board.GetBoard();

        if (positY - 1 >= 0 && matrixBoard[positY - 1][positX] == nullptr) {
            result[positY - 1][positX] = MATRIX_INTENTIFICATOR::CAN_MOVE;
        }
        if (positY - 1 >= 0
            && positX - 1 >= 0
            && matrixBoard[positY - 1][positX - 1] != nullptr
            && !(matrixBoard[positY - 1][positX - 1]->IsMyTeam(matrixBoard[positY][positX]))) {
            result[positY - 1][positX - 1] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
        }
        if (positY - 1 >= 0
            && positX + 1 < matrixBoard[positY].size()
            && matrixBoard[positY - 1][positX + 1] != nullptr
            && !(matrixBoard[positY - 1][positX + 1]->IsMyTeam(matrixBoard[positY][positX]))) {
            result[positY - 1][positX] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
        }

        return result;
    }
};
