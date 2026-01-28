//判断棋盘上每点是否为禁手

#include"../gomoku.h"

void bancheck(int ban[BOARDSIZE][BOARDSIZE],int board[BOARDSIZE][BOARDSIZE]){ //利用之前的棋型检查函数即可
    banreset(ban);
    for(int i = 0;i < BOARDSIZE;i++){
        for(int j = 0;j < BOARDSIZE;j++){
            if(board[i][j] == EMPTY){
            threecheck(board,i,j);
            fourcheck(board,i,j);
            fivepluscheck(board,i,j); //先检查棋型
            if((blacklivethree + blackjumpthree) > 1 || (blacklivefour + blackchargefour + blackjumpfour) > 1 || blackfiveplus >= 1){//双活三，双四，长连
                ban[i][j] = BAN;
            }
        }
    }
    }
}