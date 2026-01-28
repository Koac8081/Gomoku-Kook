//棋盘重置

#include"../gomoku.h"

int board[BOARDSIZE][BOARDSIZE];

void boardreset(int board[BOARDSIZE][BOARDSIZE]){
    for(int i = 0;i < BOARDSIZE;i ++){
        for(int j = 0;j < BOARDSIZE;j++){
            board[i][j] = EMPTY;
        }
    }
}