// AI 最终决策

#include<stdio.h>
#include"../gomoku.h"

Move aimove() {
    mark(board, ban, aimode, blackscore, whitescore); //扫描局面获取候选点
    BestPoint firstchoices[BESTNUM];
    int num = findtopscore(aimode, blackscore, whitescore, firstchoices);
    if (num == 0) return (Move){-1, -1}; //如果无处可下，返回一个无效坐标
    int finalrow = firstchoices[0].row;
    int finalcol = firstchoices[0].col;
    int bestval = (aimode == BLACK) ? -BASE : BASE;
    //遍历候选点并进入决策树预测
    for (int i = 0; i < num; i++) {
        int r = firstchoices[i].row;
        int c = firstchoices[i].col;
        int gain = firstchoices[i].score;
        board[r][c] = aimode;
        int initial_score = (aimode == BLACK) ? gain : -gain;
        int val = decisiontree(LEVEL - 1, 3 - aimode, initial_score);
        board[r][c] = EMPTY; //回溯
        //比较并保留最优路径
        if (aimode == BLACK) {
            if (val > bestval) {
                bestval = val;
                finalrow = r;
                finalcol = c;
            }
        } else {
            if (val < bestval) {
                bestval = val;
                finalrow = r;
                finalcol = c;
            }
        }
    }
    board[finalrow][finalcol] = aimode; //正式修改棋盘
    return(Move){finalrow, finalcol}; //将步子传出去
}