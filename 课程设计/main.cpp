#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h>


#include <conio.h>
#include "Game.h"


using namespace std;

int main()
{
    Game chess;
    initgraph(480, 480);
    chess.printboard();
    chess.printstart();
    getch();
    closegraph();
    return 0;
}
