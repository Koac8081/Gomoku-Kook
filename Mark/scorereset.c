//重置棋盘分数

#include<stdio.h>
#include"../gomoku.h"

void scorereset(int score[BOARDSIZE][BOARDSIZE]){
    for(int i = 0;i < BOARDSIZE;i++){
        for(int j = 0;j < BOARDSIZE;j++){
            score[i][j] = 0;
        }
    }
}