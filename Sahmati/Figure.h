#pragma once
#include <vector>

using std::vector;
using std::pair;

enum TEAM {
    BLACK = 1,
    WHITE = 2,
};

enum MATRIX_INTENTIFICATOR {
    THIS_FIGURE,
    DANGER,
    CAN_MOVE,
    CAN_ATTACK,
};

class Figure
{
protected:
    TEAM team;

    int positX;
    int positY;

public:
    TEAM GetTeam() const {
        return team;
    }

    virtual vector<vector<MATRIX_INTENTIFICATOR>>& MatrixVarAttack(Board& board) const = 0;
    virtual bool SetVarAttack(vector<vector<MATRIX_INTENTIFICATOR>>& matrix, const Figure* figure_1, const Figure* figure_2) = 0;

    vector<vector<MATRIX_INTENTIFICATOR>> MatrixDanger(Board& board, const int& thisFigureX, const int& thisFigureY)  const {

        if (board.GetSizeY() == 0 && board.GetSizeX() == 0) return;

        vector<vector<MATRIX_INTENTIFICATOR>> result(board.GetSizeY(), vector<MATRIX_INTENTIFICATOR>(board.GetSizeX()));

        auto posit = board.PositionRotate(thisFigureX, thisFigureY);
        result[posit.second][posit.first] = MATRIX_INTENTIFICATOR::THIS_FIGURE;

        board.BoardRotate();

        auto matrixBoard = board.GetBoard();

        for (int y = 0; y < board.GetSizeY(); y++)
        {
            for (int x = 0; x < board.GetSizeX(); x++)
            {
                if (!(matrixBoard[y][x]->IsMyTeam(matrixBoard[y][x])) && matrixBoard[y][x]->ImCanAttack(board, thisFigureX, thisFigureY)) {
                    result[y][x] = MATRIX_INTENTIFICATOR::DANGER;
                }
            }
        }

        board.BoardRotate();

        return result;
    }
    bool ImCanAttack(Board& board, const int& setPosX, const int& setPosY)  const {
        auto boardCommand = this->MatrixVarAttack(board);

        return boardCommand[setPosY][setPosX] == MATRIX_INTENTIFICATOR::CAN_ATTACK;
    }
    bool ImCanMove(Board& board, const int& setPosX, const int& setPosY)  const {
        auto boardCommand = this->MatrixVarAttack(board);

        return boardCommand[setPosY][setPosX] == MATRIX_INTENTIFICATOR::CAN_MOVE;
    }


    bool IsMyTeam(const Figure* figure) {
        return team == figure->team;
    }

    void SetPositX(int x)
    {
        positX = x;
    }
    void SetPositY(int y)
    {
        positY = y;
    }

protected: 
    
};

