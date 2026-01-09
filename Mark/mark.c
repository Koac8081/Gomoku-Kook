//对整个棋盘进行打分

#include<stdio.h>
#include"../gomoku.h"

void mark(int board[BOARDSIZE][BOARDSIZE],int ban[BOARDSIZE][BOARDSIZE],int aimode){
    if(aimode == BLACK){
        for(int i = 0;i < BOARDSIZE;i++){
            for(int j = 0;j < BOARDSIZE;j++){
                if(board[i][j] == EMPTY){
                    twocheck(board,i,j);
                    threecheck(board,i,j);
                    fourcheck(board,i,j);
                    fivecheck(board,i,j);
                    fivepluscheck(board,i,j);
                    score[i][j] = 1*(blacksleeptwo + whitesleeptwo) + 2*(blacklivetwo + whitelivetwo) + 3*(blacksleepthree + whitesleepthree) + 4*(blacklivethree + whitelivethree) + 6*(blackchargefour + whitechargefour) + 9*(blacklivefour + whitelivefour);
                    if(blacklivefour >= 1){
                        score[i][j] = MUSTATTACK;
                    }
                    if(blacklivethree >= 2){
                        score[i][j] = MUSTATTACK;
                    }
                    if(blackchargefour >= 2){
                        score[i][j] = MUSTATTACK;
                    }
                    if(blacklivethree >= 1 && blackchargefour >= 1){
                        score[i][j] = MUSTATTACK;
                    }
                    if(blacklivethree >= 1 && blacklivefour >= 1){
                        score[i][j] = MUSTATTACK;
                    }
                    if(whitelivefour >= 1){
                        score[i][j] = MUSTDEFEND;
                    }
                    if(whitelivethree >= 2){
                        score[i][j] = MUSTDEFEND;
                    }
                    if(whitechargefour >= 2){
                        score[i][j] = MUSTDEFEND;
                    }
                    if(whitelivethree >= 1 && whitechargefour >= 1){
                        score[i][j] = MUSTDEFEND;
                    }
                    if(whitelivethree >= 1 && whitelivefour >= 1){
                        score[i][j] = MUSTDEFEND;
                    }
                    if(whitefive >= 1){
                        score[i][j] = MUSTDEFEND; 
                    }
                    if(ban[i][j] == BAN){
                        score[i][j] = BANNED;
                    }
                    if(blackfive >= 1){
                        score[i][j] = WINATTACK; 
                    }
                }
            }
        }
    }
    else{
        for(int i = 0;i < BOARDSIZE;i++){
            for(int j = 0;j < BOARDSIZE;j++){
                if(board[i][j] == EMPTY){
                    twocheck(board,i,j);
                    threecheck(board,i,j);
                    fourcheck(board,i,j);
                    fivecheck(board,i,j);
                    fivepluscheck(board,i,j);
                    score[i][j] = 1*(blacksleeptwo + whitesleeptwo) + 2*(blacklivetwo + whitelivetwo) + 3*(blacksleepthree + whitesleepthree) + 4*(blacklivethree + whitelivethree) + 6*(blackchargefour + whitechargefour) + 9*(blacklivefour + whitelivefour);
                    if(whitelivefour >= 1){
                        score[i][j] = MUSTATTACK;
                    }
                    if(whitelivethree >= 2){
                        score[i][j] = MUSTATTACK;
                    }
                    if(whitechargefour >= 2){
                        score[i][j] = MUSTATTACK;
                    }
                    if(whitelivethree >= 1 && whitechargefour >= 1){
                        score[i][j] = MUSTATTACK;
                    }
                    if(whitelivethree >= 1 && whitelivefour >= 1){
                        score[i][j] = MUSTATTACK;
                    }
                    if(blacklivefour >= 1){
                        score[i][j] = MUSTDEFEND;
                    }
                    if(blacklivethree >= 2){
                        score[i][j] = MUSTDEFEND;
                    }
                    if(blackchargefour >= 2){
                        score[i][j] = MUSTDEFEND;
                    }
                    if(blacklivethree >= 1 && blackchargefour >= 1){
                        score[i][j] = MUSTDEFEND;
                    }
                    if(blacklivethree >= 1 && blacklivefour >= 1){
                        score[i][j] = MUSTDEFEND;
                    }
                    if(blackfive >= 1){
                        score[i][j] = MUSTDEFEND; 
                    }
                    if(whitefive >= 1){
                        score[i][j] = WINATTACK; 
                    }
                }
            }
        }
    }
}