#pragma once
#include "Figure.h"
#include "Board.h"
class Elephant : public Figure
{
public:

    vector<vector<MATRIX_INTENTIFICATOR>>& MatrixVarAttack(Board& board) const override {

        if (board.GetSizeY() == 0 && board.GetSizeX() == 0) return;

        vector<vector<MATRIX_INTENTIFICATOR>> result(board.GetSizeY(), vector<MATRIX_INTENTIFICATOR>(board.GetSizeX()));

        result[positY][positX] = MATRIX_INTENTIFICATOR::THIS_FIGURE;
        auto matrixBoard = board.GetBoard();
        int i = 0;

        while (positX + i < board.GetSizeX() && positY + i < board.GetSizeY()) {

            if (matrixBoard[positY + i][positX + i] == nullptr) {
                result[positY + i][positX + i] = MATRIX_INTENTIFICATOR::CAN_MOVE;
            }
            else
            {
                if (!matrixBoard[positY + i][positX + i]->IsMyTeam(matrixBoard[positY + i][positX + i])) {
                    result[positY + i][positX + i] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
                }
                else break;
            }

            i++;
        }
        i = 0;

        while (positX + i < board.GetSizeX() && positY - i >= 0) {

            if (matrixBoard[positY - i][positX + i] == nullptr) {
                result[positY - i][positX + i] = MATRIX_INTENTIFICATOR::CAN_MOVE;
            }
            else
            {
                if (!matrixBoard[positY - i][positX + i]->IsMyTeam(matrixBoard[positY - i][positX + i])) {
                    result[positY - i][positX + i] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
                }
                else break;
            }

            i++;
        }
        i = 0;

        while (positX - i >= 0 && positY + i < board.GetSizeY()) {

            if (matrixBoard[positY + i][positX - i] == nullptr) {
                result[positY + i][positX - i] = MATRIX_INTENTIFICATOR::CAN_MOVE;
            }
            else
            {
                if (!matrixBoard[positY + i][positX - i]->IsMyTeam(matrixBoard[positY + i][positX - i])) {
                    result[positY + i][positX - i] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
                }
                else break;
            }

            i++;
        }
        i = 0;

        while (positX - i >= 0 && positY - i >= 0) {

            if (matrixBoard[positY - i][positX - i] == nullptr) {
                result[positY - i][positX - i] = MATRIX_INTENTIFICATOR::CAN_MOVE;
            }
            else
            {
                if (!matrixBoard[positY - i][positX - i]->IsMyTeam(matrixBoard[positY - i][positX - i])) {
                    result[positY - i][positX - i] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
                }
                else break;
            }

            i++;
        }

        return result;
    }
};

