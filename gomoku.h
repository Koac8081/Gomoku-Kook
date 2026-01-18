#pragma once//头文件开头要加的一句

#define EMPTY 0 //棋盘空位
#define WHITE 1 //白棋
#define BLACK 2 //黑棋

#define BOARDSIZE 15 //棋盘大小
#define MAXSTEP 225 //最大步数
#define BOARDMAX 14 //棋盘上边界

#define PVP 1 //人人对战
#define PVE 2 //人机对战
#define DEBUG 3 //Debug模式

#define UNDERWAY 0 //游戏进行中
#define WHITEWIN 1 //白赢
#define BLACKWIN 2 //黑赢
#define PEACE 3 //平局
#define EXIT 4 //退出

#define WHITEGO 1 //白棋做落子决策中
#define BLACKGO 2 //黑棋做落子决策中

#define PLAYERCHOSEBLACK 1 //PVE模式中，玩家选择黑棋
#define PLAYERCHOSEWHITE 2 //PVE模式中，玩家选择白棋

#define WINATTACK 600000000 //下在此处，即可胜利
#define MUSTDEFEND 1000000 //敌人下在此处，就会失败
#define MUSTDEFENDNOW 50000000 //必须立刻防守
#define MUSTATTACK 200000 //下在此处可基本确定胜利
#define BANNED -400000000 //此处是禁手
#define SLEEPTWO 20 //打分时眠二的分数
#define LIVETWO 300 //打分时活二的分数
#define SLEEPTHREE 200 //打分时眠三的分数
#define JUMPTHREE 4000 //打分时跳活三的分数
#define LIVETHREE 5000 //打分时活三的分数
#define JUMPFOUR 10000 //打分时跳四的分数
#define CHARGEFOUR 15000 //打分时冲四的分数
#define DEFENDFACTOR 1 //防御分的权重
#define NEIGHBORSCORE 20 //紧贴棋子的加分

#define NOTBAN 0 //不是黑棋禁手
#define BAN 1 //是黑棋禁手

#define BESTNUM 5 //为决策寻找的得分最高的棋子的数量
#define LEVEL 8 //决策树深度，看接下来的几手
#define BASE 2147483647 //决策基础分
#define SCOREBASE -1000000000 //搜索最高分时的基础分

typedef struct {// 寻找高分点
    int row;    // 行坐标
    int col;    // 列坐标
    int score;  // 该点的分数
} BestPoint;

typedef struct {// AI的落子
    int x;      // 行坐标
    int y;      // 列坐标
} Move;

extern int board[BOARDSIZE][BOARDSIZE]; //棋盘及状态

extern int gamemode; //游戏模式
extern int gamestate; //游戏状态
extern int goinger; //正在做落子抉择的一方
extern int row; //玩家输入的落子横坐标;棋盘上的row对应数组里的BOARDSIZE - row
extern char col; //玩家输入的落子纵坐标;棋盘上的col对应数组里的col - 'A'
extern int blackstep; //黑棋至今步数
extern int whitestep; //白棋至今步数
extern int playerchose; //PVE模式中玩家选择的一方
extern int aimode; //PVE模式中AI的一方

extern int blackfive; //黑棋下在此处形成的五连数
extern int whitefive; //白棋下在此处形成的五连数
extern int blackfiveplus; //黑棋下在此处形成的长连数
extern int whitefiveplus; //白棋下在此处形成的长连数
extern int blacklivefour; //黑棋下在此处形成的活四数
extern int whitelivefour; //白棋下在此处形成的活四数
extern int blackjumpfour; //黑棋下在此处形成的跳四数
extern int whitejumpfour; //白棋下在此处形成的跳四数
extern int blackchargefour; //黑棋下在此处形成的冲四数
extern int whitechargefour; //白棋下在此处形成的冲四数
extern int blacklivethree; //黑棋下在此处形成的活三数
extern int whitelivethree; //白棋下在此处形成的活三数
extern int blackjumpthree; //黑棋下在此处形成的跳活三数
extern int whitejumpthree; //白棋下在此处形成的跳活三数
extern int blacksleepthree; //黑棋下在此处形成的眠三数
extern int whitesleepthree; //白棋下在此处形成的眠三数
extern int blacklivetwo; //黑棋下在此处形成的活二数
extern int whitelivetwo; //白棋下在此处形成的活二数
extern int blacksleeptwo; //黑棋下在此处形成的眠二数
extern int whitesleeptwo; //白棋下在此处形成的眠二数

extern int targetrow; //检索棋盘时的目标行坐标
extern int targetcol; //检索棋盘时的目标纵坐标

extern int blackscore[BOARDSIZE][BOARDSIZE]; //棋盘上一点黑棋的分数
extern int whitescore[BOARDSIZE][BOARDSIZE]; //棋盘上一点白棋的分数

extern int ban[BOARDSIZE][BOARDSIZE]; //棋盘上一点是否为黑方禁手
extern int tempban[BOARDSIZE][BOARDSIZE]; //记录上一步下完哪里是禁手

void boardprint(int board[BOARDSIZE][BOARDSIZE],int row,char col); //棋盘打印及更新
void boardreset(int board[BOARDSIZE][BOARDSIZE]); //重置棋盘
void emptyboardprint(int board[BOARDSIZE][BOARDSIZE]); //打印空棋盘

void wincheck(int board[BOARDSIZE][BOARDSIZE],int goinger,int row,char col,int blackstep,int whitestep); //检查是否有一方胜利或平局
int wincheckforai(int board[BOARDSIZE][BOARDSIZE],int goinger,int row,int col); //供ai决策使用的wincheck

void fivecheck(int board[BOARDSIZE][BOARDSIZE],int targetrow,int targetcol);  //检查下在此处的五连数
void fivepluscheck(int board[BOARDSIZE][BOARDSIZE],int targetrow,int targetcol); //检查下在此处的长连数
void fourcheck(int board[BOARDSIZE][BOARDSIZE],int targetrow,int targetcol); //检查下在此处的活四，冲四数
void threecheck(int board[BOARDSIZE][BOARDSIZE],int targetrow,int targetcol); //检查下在此处的活三，眠三数
void twocheck(int board[BOARDSIZE][BOARDSIZE],int targetrow,int targetcol); //检查下在此处的活二，眠二数

void scorereset(int score[BOARDSIZE][BOARDSIZE]); //重置棋盘分数
void mark(int board[BOARDSIZE][BOARDSIZE],int ban[BOARDSIZE][BOARDSIZE],int aimode,int blackscore[BOARDSIZE][BOARDSIZE],int whitescore[BOARDSIZE][BOARDSIZE]); //对棋盘上每点进行打分，找出下一步最优解

void banreset(int ban[BOARDSIZE][BOARDSIZE]); //重置禁手判断
void bancheck(int ban[BOARDSIZE][BOARDSIZE],int board[BOARDSIZE][BOARDSIZE]); //判断棋盘上每点是否为禁手

Move aimove(); //AI决策
int decisiontree(int depth, int decider, int currenttotal); //决策树
int findtopscore(int decider, int blackscore[BOARDSIZE][BOARDSIZE], int whitescore[BOARDSIZE][BOARDSIZE], BestPoint candidates[BESTNUM]); //找到若干个得分最高的点，供决策树选择

/*
15 ┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐
14 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
13 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
12 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
11 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
10 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
 9 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
 8 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
 7 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
 6 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
 5 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
 4 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
 3 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
 2 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
 1 └─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘
   A B C D E F G H I J K L M N O
这是终端中的棋盘，如果直接处理数组，那么应该是
0  ┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐
1  ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
2  ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
3  ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
4  ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
5  ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
6  ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
7  ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
8  ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
9  ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
10 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
11 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
12 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
13 ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤
14 └─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘
   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
 */ 