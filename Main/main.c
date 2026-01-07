//主函数
#include<stdio.h>
#include"../gomoku.h"

int gamestate;
int gamemode;
int goinger;
int row;
char col;
int blackstep;
int whitestep;
int playerchose;
int targetrow;
int targetcol;

int main(){
    while(1){
        boardreset(board);//重置棋盘
        gamestate = UNDERWAY;//将游戏状态置为进行中
        blackstep = 0;//重置黑棋步数
        whitestep = 0;//重置白棋步数
        printf("游戏开始\n");
        printf("请选择模式：\n1.PVP\n2.PVE\n3.Debug模式\n输入“1”选择PVP模式,输入“2”选择PVE模式,输入“3”选择Debug模式\n");
        while(1){//游戏模式选择
            if(scanf("%d",&gamemode) == 1){
                if(gamemode == PVE || gamemode == PVP || gamemode == DEBUG){
                    break;
                }
                else{
                printf("您输入了1、2或3以外的数字,请重新输入!\n");
                continue;
                }
        }
            else{
                printf("输入格式有误,请重新输入!\n");
                while(getchar() != '\n');
        }
        }
        if(gamemode == PVE){//PVE游戏进行
            printf("您选择了PVE模式\n");
            printf("请选择您要成为黑方或白方:输入“1”使用黑棋进行游戏,输入“2”使用白棋进行游戏\n");
            while(1){//PVE黑白棋选择
                if(scanf("%d",&playerchose) == 1){
                    if(playerchose == PLAYERCHOSEBLACK){
                        printf("您选择了黑方\n");
                        break;
                    }
                    else if(playerchose == PLAYERCHOSEWHITE){
                        printf("您选择了白方\n");
                        break;
                    }
                    else{
                        printf("您输入了“1”或“2”以外的其他数字,请重新输入!\n");
                        continue;
                    }
                }
                else{
                    printf("输入格式错误,请重新输入!\n");
                    while(getchar() != '\n');
                }
            }
            printf("棋局开始\n");
            emptyboardprint(board);
            if(playerchose == PLAYERCHOSEBLACK){//玩家选择黑棋后的PVE游戏
            while(gamestate == UNDERWAY){
                    printf("请玩家落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
                    printf("当前黑棋（玩家）已落%d子,白棋（电脑）已落%d子\n",blackstep,whitestep);
                    while(1){//玩家（黑棋）落子
                goinger = BLACKGO;
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
            blackstep++;
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == BLACKWIN){
                printf("玩家胜利！\n重新开始游戏\n");
                break;
            }
            else if(gamestate == PEACE){
                printf("平局！\n重新开始游戏\n");
                break;
            }
        }
        
    }
            else{//玩家选择白棋后的PVP游戏
                while(gamestate == UNDERWAY){
                    printf("请玩家落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
                    printf("当前黑棋（电脑）已落%d子,白棋（玩家）已落%d子\n",blackstep,whitestep);
                    while(1){//玩家（白棋）落子
                goinger = WHITEGO;
                if(scanf("%d %c",&row,&col) == 2){
                    if(1 <= row && row <= BOARDSIZE && 1 <= col - 'A' + 1 && col - 'A' + 1 <= BOARDSIZE && board[BOARDSIZE - row][col - 'A'] == EMPTY){
                        board[BOARDSIZE - row][col - 'A'] = WHITE;
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
            whitestep++;
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == WHITEWIN){
                printf("玩家胜利！\n重新开始游戏\n");
                break;
            }
            else if(gamestate == PEACE){
                printf("平局！\n重新开始游戏\n");
                break;
            }
        }
            }
        }
        if(gamemode == PVP){//PVP游戏进行
            printf("您选择了PVP模式\n");
            printf("棋局开始\n");
            emptyboardprint(board);
            while(gamestate == UNDERWAY){
            printf("请黑方落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
            printf("当前黑棋已落%d子,白棋已落%d子\n",blackstep,whitestep);
            while(1){//黑方落子
                goinger = BLACKGO;
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
            blackstep++;
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == BLACKWIN){
                printf("黑方胜利！\n重新开始游戏\n");
                break;
            }
            else if(gamestate == PEACE){
                printf("平局！\n重新开始游戏\n");
                break;
            }
            printf("请白方落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
            printf("当前黑棋已落%d子,白棋已落%d子\n",blackstep,whitestep);
            while(1){//白方落子
                goinger = WHITEGO;
                if(scanf("%d %c",&row,&col) == 2){
                    if(1 <= row && row <= BOARDSIZE && 1 <= col - 'A' + 1 && col - 'A' + 1 <= BOARDSIZE && board[BOARDSIZE - row][col - 'A'] == EMPTY){
                        board[BOARDSIZE - row][col - 'A'] = WHITE;
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
            whitestep++;
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == WHITEWIN){
                printf("白方胜利！\n重新开始游戏\n");
                break;
            }
            else if(gamestate == PEACE){
                printf("平局！\n重新开始游戏\n");
                break;
            }
        }
        }
        if(gamemode == DEBUG){
            printf("您选择了Debug模式\n");
            printf("棋局开始\n");
            emptyboardprint(board);
            while(gamestate == UNDERWAY){
            while(1){
            printf("请输入坐标,查看对此处的判断情况；输入“0 任意字母”退出查看\n");
            scanf("%d %c",&row,&col);
            if(row == 0){
                break;
            }
            targetrow = BOARDSIZE - row;
            targetcol = col - 'A';
            fourcheck(board,targetrow,targetcol);
            fivecheck(board,targetrow,targetcol);
            fivepluscheck(board,targetrow,targetcol);
            printf("黑棋活四:%d\n",blacklivefour);
            printf("白棋活四:%d\n",whitelivefour);
            printf("黑棋冲四:%d\n",blackchargefour);
            printf("白棋冲四:%d\n",whitechargefour);
            printf("黑棋连五:%d\n",blackfive);
            printf("白棋连五:%d\n",whitefive);
            printf("黑棋长连:%d\n",blackfiveplus);
            printf("白棋长连:%d\n",whitefiveplus);
    }
        printf("请黑方落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
        printf("当前黑棋已落%d子,白棋已落%d子\n",blackstep,whitestep);
            while(1){//黑方落子
                goinger = BLACKGO;
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
            blackstep++;
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == BLACKWIN){
                printf("黑方胜利！\n重新开始游戏\n");
                break;
            }
            else if(gamestate == PEACE){
                printf("平局！\n重新开始游戏\n");
                break;
            }
            printf("请白方落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
            printf("当前黑棋已落%d子,白棋已落%d子\n",blackstep,whitestep);
            while(1){//白方落子
                goinger = WHITEGO;
                if(scanf("%d %c",&row,&col) == 2){
                    if(1 <= row && row <= BOARDSIZE && 1 <= col - 'A' + 1 && col - 'A' + 1 <= BOARDSIZE && board[BOARDSIZE - row][col - 'A'] == EMPTY){
                        board[BOARDSIZE - row][col - 'A'] = WHITE;
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
            whitestep++;
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == WHITEWIN){
                printf("白方胜利！\n重新开始游戏\n");
                break;
            }
            else if(gamestate == PEACE){
                printf("平局！\n重新开始游戏\n");
                break;
            }
    }
        }
    }
}