// AI 最终决策

#include<stdio.h>
#include"../gomoku.h"

Move aimove(){
    mark(board, ban, aimode, blackscore, whitescore); //扫描局面获取候选点
    BestPoint firstchoices[BESTNUM];
    int num = findtopscore(aimode, blackscore, whitescore, firstchoices); //调用findtopscore找出候选点
    if(num == 0){
        return (Move){-1, -1};
    } //如果无处可下，返回无效坐标
    int finalrow = firstchoices[0].row;
    int finalcol = firstchoices[0].col;
    int bestval = (aimode == BLACK) ? -BASE : BASE;
    //遍历候选点并进入决策树预测
    for (int i = 0; i < num; i++){//以找到的五个候选点为根节点，依次遍历搜索树
        int r = firstchoices[i].row;
        int c = firstchoices[i].col;
        int gain = firstchoices[i].score;
        board[r][c] = aimode;
        int initialscore = (aimode == BLACK) ? gain : -gain;
        int val = decisiontree(LEVEL - 1, 3 - aimode, initialscore);
        board[r][c] = EMPTY; //回溯，此时只是虚拟落子
        //比较并保留最优路径
        if(aimode == BLACK){
            if(val > bestval){
                bestval = val;
                finalrow = r;
                finalcol = c;
            }
        } 
        else{
            if(val < bestval){
                bestval = val;
                finalrow = r;
                finalcol = c;
            }
        }
    }
    board[finalrow][finalcol] = aimode; //正式修改棋盘
    return(Move){finalrow, finalcol}; //将步子传出去
}