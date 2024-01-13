#pragma once
#include "Board.h"


enum UIConcoleSahmati
{
    WHITE = 128,
    BLACK = 96,
    POINT = 4,
    BORD_POINT = 64,
    SELECT_FIGURE = 160,
    SELECT_BORD = 16,
};

enum UIConsoleFigureTexutre {
    DEFAULT = ' ',
    PAWN = 'p',
    ROCK = 'r',
    HOURSE = 'h',
    ELEPHANT = 'e',
    QUEEN = 'Q',
    KING = 'K',
};

class UIConsoleChess {
private:
    Board* board;


public:

};