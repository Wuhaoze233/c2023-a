//
// Created by 81524 on 2023/12/25.
//

#ifndef TEST_GOBANG_GAME_H
#define TEST_GOBANG_GAME_H
#include <string>
#include <wincon.h>

class Game {
public:
    struct Node_Tree{
        int self,cnt,score=1,depth,result=0,number=0,Alpha=-100000000,Beta=+100000000;
        int board_tmp[16][16];
        struct Node_Tree* son[100];
        COORD site[100];
        Node_Tree *Last;
    };
    /*int ScoreBoard[16][16]={0};*/
    COORD currentPos = {-3, -3};
    COORD waitPos;
    std::string atk[4]={""};
    int chessboard[16][16] = {0};
    int self = -1;
    const int step = 30;

    void printboard();

    void printchess();

    void printmouse();

    void printact();

    bool chessjudge(int x,int y,int chessboard[16][16]);

    void printend();

    void printstart();

    void Attack(int x,int y,int self,int board_tmp[16][16],int ScoreBoard[16][16]);

    int AllScore(Node_Tree *p);

    Node_Tree* createroot();

    Node_Tree* createleaf(Node_Tree *p);

    Node_Tree* Minimax(Node_Tree* p);

    void PrintScore(Node_Tree *p);

    Node_Tree* createlist(Node_Tree *p);

    void Robot();

    int ScoreGet(int empty,int count,int block,int able);

};

#endif //TEST_GOBANG_GAME_H
