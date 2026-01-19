//棋盘的打印和更新
#include<stdio.h>
#include"../gomoku.h"

void boardprint(int board[BOARDSIZE][BOARDSIZE],int row,char col){//使用了助教提供的棋盘打印函数，稍作修改
    for(int i = 0; i < BOARDSIZE; i++){
        printf("%2d ", BOARDSIZE - i);
        for (int j = 0; j < BOARDSIZE; j++){
            if (board[i][j] == BLACK){
                if (j == BOARDSIZE - 1) {
                    printf("▲\n");
                } else {
                    printf("▲─");
                }
            }
            else if (board[i][j] == WHITE){
                if (j == BOARDSIZE - 1) {
                    printf("◎\n");
                } 
                else {
                    printf("◎─");
                }
            } 
            else if (i == 0){
                if (j == 0)                   
                { printf("┌─");  }
                else if (j == BOARDSIZE - 1) 
                { printf("┐\n"); }
                else                         
                { printf("┬─");  }
            } else if (i == BOARDSIZE - 1){
                if (j == 0)                   
                { printf("└─");  }
                else if (j == BOARDSIZE - 1)
                { printf("┘\n"); }
                else                          
                { printf("┴─");  }
            } else {
                if (j == 0)                   
                { printf("├─");  }
                else if (j == BOARDSIZE - 1)
                { printf("┤\n"); }
                else                          
                { printf("┼─");  }
            }
        }
    }
    printf("  ");
    for (int i = 0; i < BOARDSIZE; i++){
        printf(" %c", 'A' + i);
    }
    printf("\n");
    if(goinger == BLACKGO){//最近一步落下棋子的位置提示
        printf("黑棋落子在:%d %c\n",row,col);
    }
    else{
        printf("白棋落子在:%d %c\n",row,col);
    }
}