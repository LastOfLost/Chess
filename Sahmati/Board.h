
#include "Figure.h"
#include <vector>

using std::vector;

class Board {
public:

    int const static DEFAULT_BORD_SIZE_X = 8;
    int const static DEFAULT_BORD_SIZE_Y = 8;

    int const static DEFAULT_INT_VALUE = 0;
private:
    vector<vector<Figure*>> board;

    bool isFirstPlayersTurn;

    int bordSizeX = DEFAULT_INT_VALUE;
    int bordSizeY = DEFAULT_INT_VALUE;

    int selectionPosX = DEFAULT_INT_VALUE;
    int selectionPosY = DEFAULT_INT_VALUE;

public:
    Board();
    Board(const int& bordSizeX, const int& bordSizeY);
    Board(const int& bordSizeX, const int& bordSizeY, const vector<vector<Figure*>>& bord);

    ~Board();

    int GetSizeX() const { 
        return bordSizeX; 
    }
    int GetSizeY() const {
        return bordSizeY; 
    }
    vector<vector<Figure*>>& GetBoard() {
        return board;
    }
    const vector<vector<Figure*>>& GetBoard() const{
        return board;
    }

    void SelectToUp();
    void SelectToDown();
    void SelectToRight();
    void SelectToLeft();

    pair<int, int> FindThisFigure(const vector<vector<Figure*>>& board);

    void BoardRotate();
    pair<int,int> PositionRotate(const int& x, const int& y);

    template <typename FigureType>
    static vector<vector<FigureType>>* BoardRotate(const vector<vector<FigureType>>& board);
    
    void StandartInit();
};

Board::Board(const int& bordSizeX, const int& bordSizeY) {
    
}

Board::Board(const int& bordSizeX, const int& bordSizeY, const vector<vector<Figure*>>& board) {
    this->bordSizeX = bordSizeX;
    this->bordSizeY = bordSizeY;
    this->board = board;
}

void Board::SelectToUp() {
    selectionPosY++;
}
void Board::SelectToDown() {
    selectionPosY++;
}
void Board::SelectToRight() {
    if(selectionPosX)
    selectionPosX++;
}
void Board::SelectToLeft(){
    selectionPosX++;
}

pair<int, int> Board::FindThisFigure(const vector<vector<Figure*>>& board) {

}

void Board::BoardRotate() {

    vector<vector<Figure*>> newBoard(board.size(), vector<Figure*>::vector(board[0].size()));
    int newY;
    int newX;

    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[y].size(); x++)
        {
            newY = board.size() - y - 1;
            newX = board[y].size() - x - 1;
            newBoard[newY][newX] = board[y][x];
            newBoard[newY][newX]->SetPositX(newX);
            newBoard[newY][newX]->SetPositY(newY);
        }
    }

    board = newBoard;
}

pair<int, int> Board::PositionRotate(const int& x, const int& y) {
    return pair<int, int>(bordSizeX - x - 1, bordSizeY - y - 1);
}

template <typename FigureType>
static vector<vector<FigureType>>* Board::BoardRotate(const vector<vector<FigureType>>& board) {

    vector<vector<FigureType>>* newBoard = new vector<vector<FigureType>>(board.size(), vector<FigureType>::vector(board[0].size()));

    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[y].size(); x++)
        {
            newBoard[board.size() - y - 1][board[y].size() - x - 1] = board[y][x];
        }
    }

    return newBoard;
}
