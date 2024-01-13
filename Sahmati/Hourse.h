#pragma once
#include "Figure.h"
#include "Board.h"
class Hourse : public Figure
{
public:

    vector<vector<MATRIX_INTENTIFICATOR>>& MatrixVarAttack(Board& board) const override {

        if (board.GetSizeY() == 0 && board.GetSizeX() == 0) return;

        vector<vector<MATRIX_INTENTIFICATOR>> result(board.GetSizeY(), vector<MATRIX_INTENTIFICATOR>(board.GetSizeX()));

        result[positY][positX] = MATRIX_INTENTIFICATOR::THIS_FIGURE;
        auto matrixBoard = board.GetBoard();

        if (positY - 2 >= 0 && positX - 1 >= 0) {
            if (matrixBoard[positY - 2][positX - 1] == nullptr) {
                result[positY - 2][positX - 1] = MATRIX_INTENTIFICATOR::CAN_MOVE;
            }
            else if (!matrixBoard[positY - 2][positX - 1]->IsMyTeam(matrixBoard[positY - 2][positX - 1])) {
                result[positY - 2][positX - 1] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
            }
        }

        else if (positY - 2 >= 0 && positX + 1 < board.GetSizeX()) {
            if (matrixBoard[positY - 2][positX + 1] == nullptr) {
                result[positY - 2][positX + 1] = MATRIX_INTENTIFICATOR::CAN_MOVE;
            }
            else if (!matrixBoard[positY - 2][positX + 1]->IsMyTeam(matrixBoard[positY - 2][positX + 1])) {
                result[positY - 2][positX + 1] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
            }
        }

        else if (positY + 2 < board.GetSizeY() && positX - 1 >= 0) {
            if (matrixBoard[positY + 2][positX - 1] == nullptr) {
                result[positY + 2][positX - 1] = MATRIX_INTENTIFICATOR::CAN_MOVE;
            }
            else if (!matrixBoard[positY + 2][positX - 1]->IsMyTeam(matrixBoard[positY + 2][positX - 1])) {
                result[positY + 2][positX - 1] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
            }
        }

        else if (positY + 2 < board.GetSizeY() && positX + 1 < board.GetSizeX()) {
            if (matrixBoard[positY + 2][positX + 1] == nullptr) {
                result[positY + 2][positX + 1] = MATRIX_INTENTIFICATOR::CAN_MOVE;
            }
            else if (!matrixBoard[positY + 2][positX + 1]->IsMyTeam(matrixBoard[positY + 2][positX + 1])) {
                result[positY + 2][positX + 1] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
            }
        }


		else if (positY - 1 >= 0 && positX - 2 >= 0) {
			if (matrixBoard[positY - 1][positX - 2] == nullptr) {
				result[positY - 1][positX - 2] = MATRIX_INTENTIFICATOR::CAN_MOVE;
			}
			else if (!matrixBoard[positY - 1][positX - 2]->IsMyTeam(matrixBoard[positY - 1][positX - 2])) {
				result[positY - 1][positX - 2] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
			}
		}

		else if (positY - 1 >= 0 && positX + 2 < board.GetSizeX()) {
			if (matrixBoard[positY - 1][positX + 2] == nullptr) {
				result[positY - 1][positX + 2] = MATRIX_INTENTIFICATOR::CAN_MOVE;
			}
			else if (!matrixBoard[positY - 1][positX + 2]->IsMyTeam(matrixBoard[positY - 1][positX + 2])) {
				result[positY - 1][positX + 2] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
			}
		}

		else if (positY + 1 < board.GetSizeY() && positX - 2 >= 0) {
			if (matrixBoard[positY + 1][positX - 2] == nullptr) {
				result[positY + 1][positX - 2] = MATRIX_INTENTIFICATOR::CAN_MOVE;
			}
			else if (!matrixBoard[positY + 1][positX - 2]->IsMyTeam(matrixBoard[positY + 1][positX - 2])) {
				result[positY + 1][positX - 2] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
			}
		}

		else if (positY + 1 < board.GetSizeY() && positX + 2 < board.GetSizeX()) {
			if (matrixBoard[positY + 1][positX + 2] == nullptr) {
				result[positY + 1][positX + 2] = MATRIX_INTENTIFICATOR::CAN_MOVE;
			}
			else if (!matrixBoard[positY + 1][positX + 2]->IsMyTeam(matrixBoard[positY + 1][positX + 2])) {
				result[positY + 1][positX + 2] = MATRIX_INTENTIFICATOR::CAN_ATTACK;
			}
		}

        return result;
    }
};