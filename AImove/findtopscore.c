// 为决策寻找重要性最高的空位

#include<stdio.h>
#include"../gomoku.h"

int findtopscore(int decider, int blackscore[BOARDSIZE][BOARDSIZE], int whitescore[BOARDSIZE][BOARDSIZE], BestPoint candidates[BESTNUM]) {
    int foundcount = 0;
    for (int k = 0; k < BESTNUM; k++) {
        candidates[k].score = -100000000; //统一找最高分
    }//初始化候选名单的分数
    for (int i = 0; i < BOARDSIZE; i++) {
        for (int j = 0; j < BOARDSIZE; j++) {
            int current_val = blackscore[i][j] + whitescore[i][j];
            //如果当前点比候选名单里最弱的一个强
            if (current_val > candidates[BESTNUM - 1].score) {
                candidates[BESTNUM - 1].row = i;
                candidates[BESTNUM - 1].col = j;
                candidates[BESTNUM - 1].score = current_val;
                //冒泡排序，把最高分排在 candidates[0]
                for (int m = BESTNUM - 1; m > 0; m--) {
                    if (candidates[m].score > candidates[m - 1].score) {
                        BestPoint temp = candidates[m];
                        candidates[m] = candidates[m - 1];
                        candidates[m - 1] = temp;
                    } else break;
                }
                if (foundcount < BESTNUM) foundcount++;
            }
        }
    }
    return foundcount; //返回实际找到的有效点个数
}