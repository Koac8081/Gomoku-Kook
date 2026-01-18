//对棋盘上每点进行打分，找出下一步的最优点

#include<stdio.h>
#include"../gomoku.h"

void mark(int board[BOARDSIZE][BOARDSIZE],int ban[BOARDSIZE][BOARDSIZE],int aimode,int blackscore[BOARDSIZE][BOARDSIZE],int whitescore[BOARDSIZE][BOARDSIZE]){//初版只对决策方打分，但是考虑到博弈树，对双方都应打分；注意到函数体没有用到aimode这个变量，因为该函数是在决策树之前完成的，当时用于逐方打分
    scorereset(blackscore);
    scorereset(whitescore);
    bancheck(ban,board); //bancheck是对全局进行
        for(int i = 0;i < BOARDSIZE;i++){
            for(int j = 0;j < BOARDSIZE;j++){
                if(board[i][j] == EMPTY){
                    twocheck(board,i,j);
                    threecheck(board,i,j);
                    fourcheck(board,i,j);
                    fivecheck(board,i,j);
                    fivepluscheck(board,i,j); //先查出棋型
                    blackscore[i][j] = SLEEPTWO*(blacksleeptwo + DEFENDFACTOR*whitesleeptwo) + LIVETWO*(blacklivetwo + DEFENDFACTOR*whitelivetwo) + SLEEPTHREE*(blacksleepthree + DEFENDFACTOR*whitesleepthree) + JUMPTHREE*(blackjumpthree + DEFENDFACTOR*whitejumpthree) + LIVETHREE*(blacklivethree + DEFENDFACTOR*whitelivethree) + CHARGEFOUR*(blackchargefour + DEFENDFACTOR*whitechargefour) + JUMPFOUR*(blackjumpfour + DEFENDFACTOR*whitejumpfour);
                    if(blacklivefour >= 1){
                        blackscore[i][j] = blackscore[i][j] + MUSTATTACK;
                    }//活四
                    if((blacklivethree + blackjumpthree) >= 2){
                        blackscore[i][j] = blackscore[i][j] + MUSTATTACK;
                    }//双活三
                    if(blackchargefour + blackjumpfour >= 2){
                        blackscore[i][j] = blackscore[i][j] + MUSTATTACK;
                    }//双冲四
                    if(blacklivethree + blackjumpthree >= 1 && blackchargefour + blackjumpfour >= 1){
                        blackscore[i][j] = blackscore[i][j] + MUSTATTACK;
                    }//活三+冲四
                    if(blacklivethree + blackjumpthree >= 1 && blacklivefour >= 1){
                        blackscore[i][j] = blackscore[i][j] + MUSTATTACK;
                    }//活三+活四
                    if(whitelivefour >= 1){
                        blackscore[i][j] = blackscore[i][j] + MUSTDEFEND;
                    }//防守白棋
                    if(whitelivethree + whitejumpthree >= 2){
                        blackscore[i][j] = blackscore[i][j] + MUSTDEFEND;
                    }
                    if(whitechargefour + whitejumpfour >= 2){
                        blackscore[i][j] = blackscore[i][j] + MUSTDEFEND;
                    }
                    if(whitelivethree + whitejumpthree >= 1 && whitechargefour + whitejumpfour >= 1){
                        blackscore[i][j] = blackscore[i][j] + MUSTDEFEND;
                    }
                    if(whitelivethree + whitejumpthree >= 1 && whitelivefour >= 1){
                        blackscore[i][j] = blackscore[i][j] + MUSTDEFEND;
                    }
                    if(whitefive >= 1){
                        blackscore[i][j] = blackscore[i][j] + MUSTDEFENDNOW; 
                    }
                    if(whitefiveplus >= 1){
                        blackscore[i][j] = blackscore[i][j] + MUSTDEFENDNOW;
                    }
                    if(ban[i][j] == BAN){
                        blackscore[i][j] = blackscore[i][j] + BANNED;
                    }
                    if(blackfive >= 1){
                        blackscore[i][j] = blackscore[i][j] + WINATTACK; 
                    }//必胜处
                    whitescore[i][j] = SLEEPTWO*(DEFENDFACTOR*blacksleeptwo + whitesleeptwo) + LIVETWO*(DEFENDFACTOR*blacklivetwo + whitelivetwo) + SLEEPTHREE*(DEFENDFACTOR*blacksleepthree + whitesleepthree) + JUMPTHREE*(DEFENDFACTOR*blackjumpthree + whitejumpthree) + LIVETHREE*(DEFENDFACTOR*blacklivethree + whitelivethree) + CHARGEFOUR*(DEFENDFACTOR*blackchargefour + whitechargefour) + JUMPFOUR*(DEFENDFACTOR*blackjumpfour + whitejumpfour);
                    if(whitelivefour >= 1){
                        whitescore[i][j] = whitescore[i][j] + MUSTATTACK;
                    }
                    if(whitelivethree + whitejumpthree >= 2){
                        whitescore[i][j] = whitescore[i][j] + MUSTATTACK;
                    }
                    if(whitechargefour + whitejumpfour >= 2){
                        whitescore[i][j] = whitescore[i][j] + MUSTATTACK;
                    }
                    if(whitelivethree + whitejumpthree >= 1 && whitechargefour + whitejumpfour >= 1){
                        whitescore[i][j] = whitescore[i][j] + MUSTATTACK;
                    }
                    if(whitelivethree + whitejumpthree >= 1 && whitelivefour >= 1){
                        whitescore[i][j] = whitescore[i][j] + MUSTATTACK;
                    }
                    if(ban[i][j] != BAN){//黑棋的禁手处不用防守
                    if(blacklivefour >= 1){
                        whitescore[i][j] = whitescore[i][j] + MUSTDEFENDNOW;
                    }
                    if(blacklivethree + blackjumpthree >= 2){
                        whitescore[i][j] = whitescore[i][j] + MUSTDEFEND;
                    }
                    if(blackchargefour + blackjumpfour>= 2){
                        whitescore[i][j] = whitescore[i][j] + MUSTDEFEND;
                    }
                    if(blacklivethree + blackjumpthree >= 1 && blackchargefour + blackjumpfour>= 1){
                        whitescore[i][j] = whitescore[i][j] + MUSTDEFEND;
                    }
                    if(blacklivethree + blackjumpthree >= 1 && blacklivefour >= 1){
                        whitescore[i][j] = whitescore[i][j] + MUSTDEFEND;
                    }
                    if(blackfive >= 1){
                        whitescore[i][j] = whitescore[i][j] + MUSTDEFENDNOW; 
                    }
                }
                    if(whitefive >= 1){
                        whitescore[i][j] = whitescore[i][j] + WINATTACK; 
                    }
                    if(whitefiveplus >= 1){
                        whitescore[i][j] = whitescore[i][j] + WINATTACK;
                    }//白棋长连也可
                    if (board[i][j] == EMPTY) {
    //发现棋局ai不太喜欢贴近防守活三，而是跳一格去防守跳三，加入贴近加分
    int neighbor_count = 0; // 检查周围 8 个格子
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue; //跳过中心点
            int ni = i + di;
            int nj = j + dj;
            //确保坐标不越界
            if (ni >= 0 && ni < BOARDSIZE && nj >= 0 && nj < BOARDSIZE) {
                if (board[ni][nj] != EMPTY) {
                    neighbor_count++;
                }
            }
        }
    }
    // 给贴身的点增加权重
    if (neighbor_count > 0) {
        // 确保它能微调决策，但不会干扰到大分
        blackscore[i][j] += neighbor_count * NEIGHBORSCORE; 
        whitescore[i][j] += neighbor_count * NEIGHBORSCORE;
    }
}
                }
            }
        }
    }