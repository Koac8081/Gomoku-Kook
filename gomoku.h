#pragma once

#define EMPTY 0 //棋盘空位
#define WHITE 1 //白棋
#define BLACK 2 //黑棋
#define BOARDSIZE 15 //棋盘大小
#define PVP 1 //人人对战
#define PVE 2 //人机对战
#define UNDERWAY 0 //游戏进行中
#define WHITEWIN 1 //白赢
#define BLACKWIN 2 //黑赢
#define PEACE 3 //平局

extern int board[BOARDSIZE][BOARDSIZE]; //棋盘及状态
extern int gamemode; //游戏模式
extern int gamestate; //游戏状态

void boardprint(int board[BOARDSIZE][BOARDSIZE],int row,char col); //棋盘打印及更新
void boardreset(int board[BOARDSIZE][BOARDSIZE]); //重置棋盘