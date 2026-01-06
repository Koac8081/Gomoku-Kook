#pragma once//头文件开头要加的一句

#define EMPTY 0 //棋盘空位
#define WHITE 1 //白棋
#define BLACK 2 //黑棋

#define BOARDSIZE 15 //棋盘大小
#define MAXSTEP 225 //最大步数

#define PVP 1 //人人对战
#define PVE 2 //人机对战

#define UNDERWAY 0 //游戏进行中
#define WHITEWIN 1 //白赢
#define BLACKWIN 2 //黑赢
#define PEACE 3 //平局

#define WHITEGO 1 //白棋做落子决策中
#define BLACKGO 2 //黑棋做落子决策中

#define PLAYERCHOSEBLACK 1 //PVE模式中，玩家选择黑棋
#define PLAYERCHOSEWHITE 2 //PVE模式中，玩家选择白棋

extern int board[BOARDSIZE][BOARDSIZE]; //棋盘及状态
extern int gamemode; //游戏模式
extern int gamestate; //游戏状态
extern int goinger; //正在做落子抉择的一方
extern int row; //玩家输入的落子横坐标;棋盘上的row对应数组里的BOARDSIZE - row
extern char col; //玩家输入的落子纵坐标;棋盘上的col对应数组里的col - 'A'
extern int blackstep; //黑棋至今步数
extern int whitestep; //白棋至今步数
extern int playerchose; //PVE模式中玩家选择的一方

extern int blackfive; //黑棋下在此处形成的五连数
extern int whitefive; //白棋下在此处形成的五连数
extern int blackfiveplus; //黑棋下在此处形成的长连数
extern int whitefiveplus; //白棋下在此处形成的长连数

extern int targetrow; //检索棋盘时的目标行坐标
extern int targetcol; //检索棋盘时的目标纵坐标

void boardprint(int board[BOARDSIZE][BOARDSIZE],int row,char col); //棋盘打印及更新
void boardreset(int board[BOARDSIZE][BOARDSIZE]); //重置棋盘
void emptyboardprint(int board[BOARDSIZE][BOARDSIZE]); //打印空棋盘

void wincheck(int board[BOARDSIZE][BOARDSIZE],int goinger,int row,char col,int blackstep,int whitestep); //检查是否有一方胜利或平局

void fivecheck(int board[BOARDSIZE][BOARDSIZE],int goinger,int targetrow,int targetcol);  //检查下在此处的五连数
void fivepluscheck(int board[BOARDSIZE][BOARDSIZE],int goinger,int targetrow,int targetcol); //检查下在此处的长连数

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