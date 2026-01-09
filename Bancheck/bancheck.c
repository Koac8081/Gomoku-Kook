//判断棋盘上每点是否为禁手

#include<stdio.h>
#include"../gomoku.h"

void bancheck(int ban[BOARDSIZE][BOARDSIZE],int board[BOARDSIZE][BOARDSIZE]){
    banreset(ban);
    for(int i = 0;i < BOARDSIZE;i++){
        for(int j = 0;j < BOARDSIZE;j++){
            if(board[i][j] == EMPTY){
            threecheck(board,i,j);
            fourcheck(board,i,j);
            fivepluscheck(board,i,j);
            if(blacklivethree > 1 || (blacklivefour + blackchargefour) > 1 || blackfiveplus >= 1){
                ban[i][j] = BAN;
            }
        }
    }
    }
}