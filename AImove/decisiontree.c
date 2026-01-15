// 决策树

#include<stdio.h>
#include"../gomoku.h"

int decisiontree(int depth, int decider, int currenttotal) {
    if (depth <= 0) {
        return currenttotal;
    } //递归终点，depth 为 0 时才停止
    BestPoint choices[BESTNUM];
    mark(board, ban, decider, blackscore, whitescore); //进行打分
    int num = findtopscore(decider, blackscore, whitescore, choices);
    if (num == 0) return currenttotal; // 如果没地方下，直接返回当前分
    if (decider == BLACK) {
        int maxscore = -BASE; //防止 maxscore 无法被更新
        for (int i = 0; i < num; i++) {
            int r = choices[i].row;
            int c = choices[i].col;
            int gain = choices[i].score;
            board[r][c] = BLACK;
            //胜负判定
            /*if (wincheckforai(board, BLACKGO, r, c) == BLACKWIN) {
                board[r][c] = EMPTY;
                return BASE; 
            }*/
            int val = decisiontree(depth - 1, WHITE, currenttotal + gain); //递归：黑棋落子，currenttotal 增加 gain
            board[r][c] = EMPTY; 
            if (val > maxscore) maxscore = val;
        }
        return maxscore;
    } 
    else {
        // 白棋
        int minscore = -BASE; 
        for (int i = 0; i < num; i++) {
            int r = choices[i].row;
            int c = choices[i].col;
            int gain = choices[i].score;
            board[r][c] = WHITE;
            /*if (wincheckforai(board, WHITEGO, r, c) == WHITEWIN) {
                board[r][c] = EMPTY;
                return BASE; 
            }*/
            int val = decisiontree(depth - 1, BLACK, currenttotal - gain);
            board[r][c] = EMPTY; 
            if (val < minscore) minscore = val;
        }
        return minscore;
    }
}