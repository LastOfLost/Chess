#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "Default_oper.h"
using namespace std;
//
//Object* Pawn(Object*& ob, int posX, int posY, char mode) {
//    if (ob == nullptr) {
//        ob = new Object;
//    }
//    ob->enable = true;
//    ob->colour = mode;
//    ob->sizeMove = 1;
//    ob->type = PAWN;
//    ob->move = new int[ob->sizeMove] {2};
//    ob->sizehod = 1;
//    ob->texture = 127;
//    ob->posX = posX;
//    ob->posY = posY;
//    return ob;
//}
//Object* Rook(Object*& ob, int posX, int posY, char mode) {
//    if (ob == nullptr) {
//        ob = new Object;
//    }
//    ob->enable = true;
//    ob->colour = mode;
//    ob->sizeMove = 4;
//    ob->type = ROOK;
//    ob->move = new int[ob->sizeMove]{2,4,6,8};
//    ob->sizehod = 8;
//    ob->texture = 5;
//    ob->posX = posX;
//    ob->posY = posY;
//    return ob;
//}
//Object* Hourse(Object*& ob, int posX, int posY, char mode) {
//    if (ob == nullptr) {
//        ob = new Object;
//    }
//    ob->enable = true;
//    ob->colour = mode;
//    ob->sizeMove = 8;
//    ob->type = HOURSE;
//    ob->move = new int[ob->sizeMove]{1,2,3,4,5,6,7,8};
//    ob->sizehod = 0;
//    ob->texture = 201;
//    ob->posX = posX;
//    ob->posY = posY;
//    return ob;
//}
//Object* Elephant(Object*& ob, int posX, int posY, char mode) {
//    if (ob == nullptr) {
//        ob = new Object;
//    }
//    ob->enable = true;
//    ob->colour = mode;
//    ob->sizeMove = 4;
//    ob->type = ELEPHANT;
//    ob->move = new int[ob->sizeMove]{1,3,5,7};
//    ob->sizehod = 8;
//    ob->texture = 'i';
//    ob->posX = posX;
//    ob->posY = posY;
//    return ob;
//}
//Object* Queen(Object*& ob, int posX, int posY, char mode) {
//    if (ob == nullptr) {
//        ob = new Object;
//    }
//    ob->enable = true;
//    ob->colour = mode;
//    ob->sizeMove = 8;
//    ob->type = QUEEN;
//    ob->move = new int[ob->sizeMove]{1,2,3,4,5,6,7,8};
//    ob->sizehod = 8;
//    ob->texture = 'Q';
//    ob->posX = posX;
//    ob->posY = posY;
//    return ob;
//}
//Object* King(Object*& ob, int posX, int posY, char mode) {
//    if (ob == nullptr) {
//        ob = new Object;
//    }
//    ob->enable = true;
//    ob->colour = mode;
//    ob->sizeMove = 8;
//    ob->type = KING;
//    ob->move = new int[ob->sizeMove]{1,2,3,4,5,6,7,8};
//    ob->sizehod = 1;
//    ob->texture = 'W';
//    ob->posX = posX;
//    ob->posY = posY;
//    return ob;
//}
//Board* StandartBord(Board*& board, int players) {
//    if (board != nullptr) {
//        return board;
//    }
//    board = new Board;
//    board->board = new Object * *[board->size]{};
//    for (int a = 0; a < board->size; a++) {
//        board->board[a] = new Object *[board->size]{};
//    }
//    for (int pl = 0; pl < board->players; pl++) {
//        for (int a = 0; a < board->size; a++) {
//            board->board[1 + pl * 5][a] = Pawn(board->board[1 + pl * 5][a], a, 1 + pl * 5, pl * 15);
//        }
//        Rook(board->board[pl * 7][0], pl * 7, 0, pl * 15);
//        Hourse(board->board[pl * 7][1], pl * 7, 1, pl * 15);
//        Elephant(board->board[pl * 7][2], pl * 7, 2, pl * 15);
//        Queen(board->board[pl * 7][3], pl * 7, 3, pl * 15);
//        King(board->board[pl * 7][4], pl * 7, 4, pl * 15);
//        Elephant(board->board[pl * 7][5], pl * 7, 5, pl * 15);
//        Hourse(board->board[pl * 7][6], pl * 7, 6, pl * 15);
//        Rook(board->board[pl * 7][7], pl * 7, 7, pl * 15);
//    }
//
//    board->matrix = new unsigned char**[board->size]{};
//    for (int a = 0; a < board->size; a++) {
//        board->matrix[a] = new unsigned char*[board->size]{};
//        for (int b = 0; b < board->size; b++) {
//            board->matrix[a][b] = new unsigned char[MAX]{};
//        }
//    } 
//    return board;
//}
//
//int positColor(int a, int b) {
//    if ((a + b) % 2 == 0) {
//        return Board::WHITE;
//    }
//    else {
//        return Board::BLACK;
//    }
//}
//bool provPlayer(Object* ob, Object* op) {
//    if (ob->colour == op->colour) {
//        return false;
//    }
//    return true;
//}
//bool b_SelObj(Board* board, const int& posX, const int& posY, const int& orgX, const int& orgY) {
//    if (posX >= board->size || posX < 0 || posY >= board->size || posY < 0) {
//        return true;
//    }
//    if (orgX >= board->size || orgX < 0 || orgY >= board->size || orgY < 0) {
//        return true;
//    }
//
//    if (board->board[posY][posX] == nullptr) {
//        if (board->matrix[posY][posX][BORDCOL] == 0)
//            board->matrix[posY][posX][BORDCOL] = positColor(posY, posX);
//        if (board->matrix[posY][posX][TEXTURE] == 0) {
//            board->matrix[posY][posX][TEXTURE] = '*';
//            board->matrix[posY][posX][OBJCOL] = Board::POINT;
//        }
//        return false;
//    }
//    else {
//        if (provPlayer(board->board[orgY][orgX], board->board[posY][posX])) {
//            if (board->matrix[posY][posX][BORDCOL] == 0)
//                board->matrix[posY][posX][BORDCOL] = Board::BORDPOINT;
//            if (board->matrix[posY][posX][TEXTURE] == 0) {
//                board->matrix[posY][posX][TEXTURE] = board->board[posY][posX]->texture;
//                board->matrix[posY][posX][OBJCOL] = board->board[posY][posX]->colour;
//            }
//        }
//        return true;
//    }
//}
//void _SelObj(Board* board, const int& posX, const int& posY, const int& orgX, const int& orgY) {
//    if (posX >= board->size || posX < 0 || posY >= board->size || posY < 0) {
//        return;
//    }
//    if (orgX >= board->size || orgX < 0 || orgY >= board->size || orgY < 0) {
//        return;
//    }
//
//    if (board->board[posY][posX] == nullptr ) {
//        if (board->matrix[posY][posX][BORDCOL] == 0)
//        board->matrix[posY][posX][BORDCOL] = positColor(posY, posX);
//        if (board->matrix[posY][posX][TEXTURE] == 0) {
//            board->matrix[posY][posX][TEXTURE] = '*'; 
//            board->matrix[posY][posX][OBJCOL] = Board::POINT;
//        }
//    }
//    else if (provPlayer(board->board[orgY][orgX], board->board[posY][posX])) {
//        if (board->matrix[posY][posX][BORDCOL] == 0)
//            board->matrix[posY][posX][BORDCOL] = Board::BORDPOINT;
//        if (board->matrix[posY][posX][TEXTURE] == 0) {
//            board->matrix[posY][posX][TEXTURE] = board->board[posY][posX]->texture;
//            board->matrix[posY][posX][OBJCOL] = board->board[posY][posX]->colour;
//        }
//    }
//}
//
//void PawnHod(Board* board, int posX, int posY) {
//    if (board->rotateBord == true && board->board[posY][posX]->colour == WHITE) {
//        if (posY - 1 >= 0) {
//            if (posX - 1 >= 0 && board->board[posY - 1][posX - 1] != nullptr && provPlayer(board->board[posY - 1][posX - 1], board->board[posY][posX])) {
//                if (board->matrix[posY - 1][posX - 1][BORDCOL] == 0)
//                    board->matrix[posY - 1][posX - 1][BORDCOL] = Board::BORDPOINT;
//                if (board->matrix[posY - 1][posX - 1][TEXTURE] == 0) {
//                    board->matrix[posY - 1][posX - 1][OBJCOL] = board->board[posY - 1][posX - 1]->colour;
//                    board->matrix[posY - 1][posX - 1][TEXTURE] = board->board[posY - 1][posX - 1]->texture;
//                }
//            }
//            if (posX + 1 < board->size && board->board[posY - 1][posX + 1] != nullptr && provPlayer(board->board[posY - 1][posX + 1], board->board[posY][posX])) {
//                if (board->matrix[posY - 1][posX + 1][BORDCOL] == 0)
//                    board->matrix[posY - 1][posX + 1][BORDCOL] = Board::BORDPOINT;
//                if (board->matrix[posY - 1][posX + 1][TEXTURE] == 0) {
//                    board->matrix[posY - 1][posX + 1][OBJCOL] = board->board[posY - 1][posX + 1]->colour;
//                    board->matrix[posY - 1][posX + 1][TEXTURE] = board->board[posY - 1][posX + 1]->texture;
//                }
//            }
//            if (board->board[posY - 1][posX] == nullptr) {
//                if (board->matrix[posY - 1][posX][BORDCOL] == 0)
//                    board->matrix[posY - 1][posX][BORDCOL] = positColor(posY - 1, posX);
//                if (board->matrix[posY - 1][posX][TEXTURE] == 0) {
//                    board->matrix[posY - 1][posX][OBJCOL] = Board::POINT;
//                    board->matrix[posY - 1][posX][TEXTURE] = '*';
//                }
//                if (board->board[posY - 2][posX] == nullptr) {
//                    if (board->matrix[posY - 2][posX][BORDCOL] == 0)
//                        board->matrix[posY - 2][posX][BORDCOL] = positColor(posY - 2, posX);
//                    if (board->matrix[posY - 2][posX][TEXTURE] == 0) {
//                        board->matrix[posY - 2][posX][OBJCOL] = Board::POINT;
//                        board->matrix[posY - 2][posX][TEXTURE] = '*';
//                    }
//                }
//            }
//        }
//    }
//    else {
//        if (posY + 1 < board->size) {
//            if (posX - 1 >= 0 && board->board[posY + 1][posX - 1] != nullptr && provPlayer(board->board[posY + 1][posX - 1], board->board[posY][posX])) {
//                if (board->matrix[posY + 1][posX - 1][BORDCOL] == 0)
//                    board->matrix[posY + 1][posX - 1][BORDCOL] = Board::BORDPOINT;
//                if (board->matrix[posY + 1][posX - 1][TEXTURE] == 0) {
//                    board->matrix[posY + 1][posX - 1][OBJCOL] = board->board[posY + 1][posX - 1]->colour;
//                    board->matrix[posY + 1][posX - 1][TEXTURE] = board->board[posY + 1][posX - 1]->texture;
//                }
//            }
//            if (posX + 1 < board->size && board->board[posY + 1][posX + 1] != nullptr && provPlayer(board->board[posY + 1][posX + 1], board->board[posY][posX])) {
//                if (board->matrix[posY + 1][posX + 1][BORDCOL] == 0)
//                    board->matrix[posY + 1][posX + 1][BORDCOL] = Board::BORDPOINT;
//                if (board->matrix[posY + 1][posX + 1][TEXTURE] == 0) {
//                    board->matrix[posY + 1][posX + 1][OBJCOL] = board->board[posY + 1][posX + 1]->colour;
//                    board->matrix[posY + 1][posX + 1][TEXTURE] = board->board[posY + 1][posX + 1]->texture;
//                }
//            }
//            if (board->board[posY + 1][posX] == nullptr) {
//                if (board->matrix[posY + 1][posX][BORDCOL] == 0)
//                    board->matrix[posY + 1][posX][BORDCOL] = positColor(posY + 1, posX);
//                if (board->matrix[posY + 1][posX][TEXTURE] == 0) {
//                    board->matrix[posY + 1][posX][OBJCOL] = Board::POINT;
//                    board->matrix[posY + 1][posX][TEXTURE] = '*';
//                }
//                if (board->board[posY + 2][posX] == nullptr && board->board[posY][posX]->startPosit) {
//                    if (board->matrix[posY][posX][BORDCOL] == 0)
//                        board->matrix[posY + 2][posX][BORDCOL] = positColor(posY + 2, posX);
//                    if (board->matrix[posY + 2][posX][TEXTURE] == 0) {
//                        board->matrix[posY + 2][posX][OBJCOL] = Board::POINT;
//                        board->matrix[posY + 2][posX][TEXTURE] = '*';
//                    }
//                }
//            }
//        }
//    }
//}
//void RookHod(Board* board, int posX, int posY) {
//    for (int a = posY - 1; a >= 0; a--) {
//        if (b_SelObj(board, posX, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY + 1; a < board->size; a++) {
//        if (b_SelObj(board, posX, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posX - 1; a >= 0; a--) {
//        if (b_SelObj(board, a, posY, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posX + 1; a < board->size; a++) {
//        if (b_SelObj(board, a, posY, posX, posY)) {
//            break;
//        }
//    }
//}
//void HourseHod(Board* board, int posX, int posY) {
//    _SelObj(board, posX - 2, posY - 1, posX, posY);
//    _SelObj(board, posX + 2, posY - 1, posX, posY);
//    _SelObj(board, posX - 2, posY + 1, posX, posY);
//    _SelObj(board, posX + 2, posY + 1, posX, posY);
//    _SelObj(board, posX - 1, posY - 2, posX, posY);
//    _SelObj(board, posX + 1, posY - 2, posX, posY);
//    _SelObj(board, posX - 1, posY + 2, posX, posY);
//    _SelObj(board, posX + 1, posY + 2, posX, posY);
//}
//void ElephantHod(Board* board, int posX, int posY) {
//    for (int a = posY + 1, b = posX + 1; a < board->size && b < board->size; a++,b++) {
//        if (b_SelObj(board, b, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY + 1, b = posX - 1; a < board->size && b >= 0; a++, b--) {
//        if (b_SelObj(board, b, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY - 1, b = posX + 1; a >= 0 && b < board->size; a--, b++) {
//        if (b_SelObj(board, b, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY - 1, b = posX - 1; b >= 0 && a >= 0; a--, b--) {
//        if (b_SelObj(board, b, a, posX, posY)) {
//            break;
//        }
//    }
//}
//void QueenHod(Board* board, int posX, int posY) {
//    for (int a = posY + 1, b = posX + 1; a < board->size && b < board->size; a++, b++) {
//        if (b_SelObj(board, b, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY + 1, b = posX - 1; a < board->size && b >= 0; a++, b--) {
//        if (b_SelObj(board, b, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY - 1, b = posX + 1; a >= 0 && b < board->size; a--, b++) {
//        if (b_SelObj(board, b, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY - 1, b = posX - 1; b >= 0 && a >= 0; a--, b--) {
//        if (b_SelObj(board, b, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY - 1; a >= 0; a--) {
//        if (b_SelObj(board, posX, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY + 1; a < board->size; a++) {
//        if (b_SelObj(board, posX, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posX - 1; a >= 0; a--) {
//        if (b_SelObj(board, a, posY, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posX + 1; a < board->size; a++) {
//        if (b_SelObj(board, a, posY, posX, posY)) {
//            break;
//        }
//    }
//}
//void KingHod(Board* board, int posX, int posY) {
//    bool prov = true;
//    for (int a = posY + 1, b = posX + 1; a < board->size && b < board->size; a++, b++) {
//    }
//    for (int a = posY + 1, b = posX - 1; a < board->size && b >= 0; a++, b--) {
//        if (b_SelObj(board, b, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY - 1, b = posX + 1; a >= 0 && b < board->size; a--, b++) {
//        if (b_SelObj(board, b, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY - 1, b = posX - 1; b >= 0 &&  b >= 0; a--, b--) {
//        if (b_SelObj(board, b, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY - 1; a >= 0; a--) {
//        if (b_SelObj(board, posX, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posY + 1; a < board->size; a++) {
//        if (b_SelObj(board, posX, a, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posX - 1; a >= 0; a--) {
//        if (b_SelObj(board, a, posY, posX, posY)) {
//            break;
//        }
//    }
//    for (int a = posX + 1; a < board->size; a++) {
//        if (b_SelObj(board, a, posY, posX, posY)) {
//            break;
//        }
//    }
//}
//
//void BordClean(Board* board) {
//    for (int a = 0; a < board->size; a++) {
//        for (int b = 0; b < board->size; b++) {
//            board->matrix[a][b][BORDCOL] = 0;
//            board->matrix[a][b][OBJCOL] = 0;
//            board->matrix[a][b][TEXTURE] = 0;
//        }
//    }
//}   
//void BordReplace(Board* board) {
//    Object* tempObj;
//    for (int a = 0; a < board->size/2; a++) {
//        for (int b = 0; b < board->size; b++) {
//            tempObj = board->board[a][b];
//            board->board[a][b] = board->board[board->size - a - 1][b];
//            board->board[board->size - a - 1][b] = tempObj;
//        }
//    }
//
//    for (int a = 0; a < board->size; a++) {
//        for (int b = 0; b < board->size/2; b++) {
//            tempObj = board->board[a][b];
//            board->board[a][b] = board->board[a][board->size - b - 1];
//            board->board[a][board->size - b - 1] = tempObj;
//        }
//    }
//
//    for (int a = 0; a < board->size; a++) {
//        for (int b = 0; b < board->size; b++) {
//            if (board->board[a][b] != nullptr) {
//                board->board[a][b]->posY = a;
//                board->board[a][b]->posX = b;
//            }
//        }
//    }
//}
//void BordUpdate(Board* board, const int& posX, const int& posY) {
//    if (board->board[posY][posX] != nullptr) {
//        board->matrix[posY][posX][BORDCOL] = Board::SELECTOBJ + board->board[posY][posX]->colour;
//        board->matrix[posY][posX][TEXTURE] = board->board[posY][posX]->texture;
//        switch (board->board[posY][posX]->type) {
//        case PAWN:
//            PawnHod(board, posX, posY);
//            break;
//
//        case ROOK:
//            RookHod(board, posX, posY);
//            break;
//
//        case HOURSE:
//            HourseHod(board, posX, posY);
//            break;
//
//        case ELEPHANT:
//            ElephantHod(board, posX, posY);
//            break;
//        case QUEEN:
//
//            QueenHod(board, posX, posY);
//            break;
//        }
//    }
//    else {
//        board->matrix[posY][posX][BORDCOL] = Board::SELECTBORD;
//        board->matrix[posY][posX][TEXTURE] = ' ';
//    }
//    for (int a = 0; a < board->size; a++) {
//        for (int b = 0; b < board->size; b++) {
//            if (board->matrix[a][b][BORDCOL] == 0)
//                board->matrix[a][b][BORDCOL] = positColor(a, b);
//            if (board->board[a][b] != nullptr) {
//                if (board->matrix[a][b][TEXTURE] == 0) {
//                    board->matrix[a][b][TEXTURE] = board->board[a][b]->texture;
//                    board->matrix[a][b][OBJCOL] = board->board[a][b]->colour;
//                }
//            }
//            else {
//                if (board->matrix[a][b][TEXTURE] == 0) {
//                    board->matrix[a][b][TEXTURE] = ' ';
//                    board->matrix[a][b][OBJCOL] = 0;
//                }
//            }
//        }
//    }
//}
//void BordPrint(Board* board) {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    for (int a = 0; a < board->size; a++) {
//        for (int b = 0; b < board->size; b++) {
//            SetConsoleTextAttribute(hConsole, board->matrix[a][b][BORDCOL] + board->matrix[a][b][OBJCOL]);
//            cout << board->matrix[a][b][TEXTURE];
//        }
//        SetConsoleTextAttribute(hConsole, 15);
//        cout << endl;
//    }
//}
//
//bool Controle(Board*& board, int& posX, int& posY) {
//    char temp = _getch();
//    if (temp == 'w' && posY - 1 >= 0) {
//        posY--;
//    }
//    else if (temp == 's' && posY + 1 < board->size) {
//        posY++;
//    }
//    else if (temp == 'a' && posX - 1 >= 0) {
//        posX--;
//    }
//    else if (temp == 'd' && posX + 1 < board->size) {
//        posX++;
//    }
//    else if (temp == 'q') {
//        return false;
//    }
//    else if (board->board[posY][posX] != nullptr && (temp == 'W' || temp == 'S' || temp == 'A' || temp == 'D')) {
//        int tempX = posX;
//        int tempY = posY;
//        while (true) {
//            if (temp == 'W' && tempY - 1 >= 0) {
//                tempY--;
//            }
//            else if (temp == 'S' && tempY + 1 < board->size) {
//                tempY++;
//            }
//            else if (temp == 'A' && tempX - 1 >= 0) {
//                tempX--;
//            }
//            else if (temp == 'D' && tempX + 1 < board->size) {
//                tempX++;
//            }
//            else if (temp == '\r') {
//                int a = board->matrix[tempY][tempX][BORDCOL];
//                if (board->matrix[tempY][tempX][TEXTURE] == '*') {
//                    board->board[tempY][tempX] = board->board[posY][posX];
//                    board->board[posY][posX] = nullptr;
//                    board->board[tempY][tempX]->posY = tempY;
//                    board->board[tempY][tempX]->posX = tempX;
//                    posX = tempX;
//                    posY = tempY;
//                }
//                else if (board->matrix[tempY][tempX][BORDCOL] == Board::BORDPOINT) {
//                    delete[] board->board[tempY][tempX];
//                    board->board[tempY][tempX] = board->board[posY][posX];
//                    board->board[posY][posX] = nullptr;
//                    board->board[tempY][tempX]->posY = tempY;
//                    board->board[tempY][tempX]->posX = tempX;
//                    posX = tempX;
//                    posY = tempY;
//                }
//                break;
//            }
//            else {
//                break;
//            }
//            BordClean(board);
//            BordUpdate(board, posX, posY);
//            board->matrix[tempY][tempX][BORDCOL] = Board::SELECTBORD;
//            system("cls");
//            BordPrint(board);
//            temp = _getch();
//        }
//        system("cls");
//        BordClean(board);
//        BordUpdate(board, posX, posY);
//        BordPrint(board);
//    }
//    return true;
//}
//void Game(Board* board) {
//    int posX = 0;
//    int posY = 0;
//    int variant = 0;
//    BordClean(board);
//    do {
//        system("cls");
//        BordUpdate(board, posX, posY);
//        BordPrint(board);
//        BordClean(board);
//    } while (Controle(board, posX, posY));
//}
//
int main() {
  /*  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    Board* board = nullptr;
    StandartBord(board, 2);
    Game(board);*/

}