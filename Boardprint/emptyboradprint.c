//打印不带落子提示的棋盘

#include"../gomoku.h"

void emptyboardprint(int board[BOARDSIZE][BOARDSIZE]){
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
}