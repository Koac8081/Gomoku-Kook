//重置禁手判断

#include"../gomoku.h"

void banreset(int ban[BOARDSIZE][BOARDSIZE]){
    for(int i = 0;i < BOARDSIZE;i++){
        for(int j = 0;j < BOARDSIZE;j++){
            ban[i][j] = NOTBAN;
        }
    }
}