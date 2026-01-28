//使用清屏命令清理屏幕
#include<stdlib.h>
#include"../gomoku.h"

void screenclean(){
#ifdef _WIN32
    system("cls"); //Windows环境下
#else
    system("clear"); //Linux环境下
#endif
}