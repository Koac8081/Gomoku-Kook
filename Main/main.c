//主函数
#include<stdio.h>
#include"../gomoku.h"

int gamestate;
int gamemode;

int main(){
    while(1){
        boardreset(board);
        int row;//行输入
        char col;//列输入
        gamestate = UNDERWAY;
        printf("游戏开始");
        printf("请选择模式：\n1.PVP\n2.PVE\n输入“1”选择PVP模式,输入“2”选择PVE模式\n");
        while(1){
            if(scanf("%d",&gamemode) == 1){
                if(gamemode == PVE || gamemode == PVP){
                    break;
                }
                else{
                printf("输入了1或2以外的数字,请重新输入!\n");
                continue;
                }
        }
            else{
                printf("输入格式有误,请重新输入!\n");
                while(getchar() != '\n');
        }
        }
        if(gamemode == PVE){
            printf("您选择了PVE模式\n");
        }
        else{
            printf("您选择了PVP模式\n");
        }
        while(gamestate == UNDERWAY){
            printf("请下棋-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
            while(1){
                if(scanf("%d %c",&row,&col) == 2){
                    if(1 <= row && row <= BOARDSIZE && 1 <= col - 'A' + 1 && col - 'A' + 1 <= BOARDSIZE && board[BOARDSIZE - row][col - 'A'] == EMPTY){
                        board[BOARDSIZE - row][col - 'A'] = BLACK;
                        break;
                    }
                    else{
                        printf("您选择的位置在不在棋盘范围或已经落子,请重新选择!\n");
                        continue;
                    }
                }
                else{
                    printf("输入格式有误,请重新输入!\n");
                    while(getchar() != '\n');
                }
            }
            boardprint(board,row,col);
        }
    }
}