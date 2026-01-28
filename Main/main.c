//主函数

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
int blackscore[BOARDSIZE][BOARDSIZE];
int whitescore[BOARDSIZE][BOARDSIZE];
int ban[BOARDSIZE][BOARDSIZE];
int tempban[BOARDSIZE][BOARDSIZE];
int aimode; //初始化一些全局变量

int main(){
    while(1){
        screenclean();
        boardreset(board);//重置棋盘
        banreset(ban);//重置黑棋禁手判断
        banreset(tempban);
        scorereset(blackscore);//重置打分
        scorereset(whitescore);
        gamestate = UNDERWAY;//将游戏状态置为进行中
        blackstep = 0;//重置黑棋步数
        whitestep = 0;//重置白棋步数
        printf("游戏开始\n");
        printf("请选择模式：\n1.PVP\n2.PVE\n3.Debug模式\n输入“1”选择PVP模式,输入“2”选择PVE模式,输入“3”选择Debug模式\n输入“4”退出\n");
        printf("提示:“▲”代表黑棋,“◎ ”代表白棋\n");
        while(1){//游戏模式选择
            if(scanf("%d",&gamemode) == 1){//输入及合法性检测
                if(gamemode == PVE || gamemode == PVP || gamemode == DEBUG){
                    break;
                }
                else if(gamemode == EXIT){
                    printf("游戏结束\n");
                    return 0;
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
            pvemode();
        }
        if(gamemode == PVP){//PVP游戏进行；与PVE差别不大，不再重复注释
           pvpmode();
        }
        if(gamemode == DEBUG){//Debug模式，显示对棋型的判断
            debugmode();   
        }
    }
    return 0;
}