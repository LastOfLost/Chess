#pragma once
#include "Figure.h"
#include "Board.h"
class Rock : public Figure
{

public:
    vector<vector<MATRIX_INTENTIFICATOR>>& MatrixVarAttack(Board& board) const override {

        if (board.GetSizeY() == 0 && board.GetSizeX() == 0) return;

        vector<vector<MATRIX_INTENTIFICATOR>> result(board.GetSizeY(), vector<MATRIX_INTENTIFICATOR>(board.GetSizeX()));

        result[positY][positX] = MATRIX_INTENTIFICATOR::THIS_FIGURE;
        auto matrixBoard = board.GetBoard();

        for (int i = positX; i < board.GetSizeX(); i++) {
            
        }

        for (int i = positX; i >= 0; i--) {
            if (matrixBoard[positY][i] == nullptr) {
                result[positY][i] = MATRIX_INTENTIFICATOR::CAN_MOVE;
            }
            else
            {
                if (!matrixBoard[positY][positX]->IsMyTeam(matrixBoard[positY][i])) {
                    result[positY][i] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
                }
                else break;
            }
        }

        for (int i = positY; i < board.GetSizeY(); i++) {
            if (matrixBoard[i][positX] == nullptr) {
                result[i][positX] = MATRIX_INTENTIFICATOR::CAN_MOVE;
            }
            else
            {
                if (!matrixBoard[i][positX]->IsMyTeam(matrixBoard[i][positX])) {
                    result[i][positX] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
                }
                else break;
            }
        }

        for (int i = positY; i >= 0; i--) {
            if (matrixBoard[i][positX] == nullptr) {
                result[i][positX] = MATRIX_INTENTIFICATOR::CAN_MOVE;
            }
            else
            {
                if (!matrixBoard[i][positX]->IsMyTeam(matrixBoard[i][positX])) {
                    result[i][positX] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
                }
                else break;
            }
        }

        return result;
    }
};

