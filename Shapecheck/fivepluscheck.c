//用于判断下在此处可形成的长连数

#include<stdio.h>
#include"../gomoku.h"

int blackfiveplus = 0; //黑棋长连
int whitefiveplus = 0; //白棋长连

void fivepluscheck(int board[BOARDSIZE][BOARDSIZE],int targetrow,int targetcol){//逻辑与五连几乎相同，不再重复注释
    blackfiveplus = 0;
    whitefiveplus = 0; //重置

    int target = BLACK;//检索目标
    if(target == BLACK){//黑棋检索
        //先纵向检索
        int colnum_up = 0;//向上连子数
        while(1){
            if(targetrow - colnum_up - 1 >= 0 && board[targetrow - colnum_up - 1][targetcol] == BLACK){
            colnum_up ++;
            }
            else{
                break;
            }
        }
        int colnum_down = 0;//向下连子数
        while(1){
            if(targetrow + colnum_down + 1 <= BOARDMAX && board[targetrow + colnum_down + 1][targetcol] == BLACK){
            colnum_down ++;
            }
            else{
                break;
            }
        }
        if(colnum_down + colnum_up + 1 > 5){
            blackfiveplus ++;
        }
        //再横向检索
        int rownum_left = 0;//向左连子数
        while(1){
            if(targetcol - rownum_left - 1 >= 0 && board[targetrow][targetcol - rownum_left - 1] == BLACK){
            rownum_left ++;
            }
            else{
                break;
            }
        }
        int rownum_right = 0;//向右连子数
        while(1){
            if(targetcol + rownum_right + 1 <= BOARDMAX && board[targetrow][targetcol + rownum_right + 1] == BLACK){
                rownum_right ++;
            }
            else{
                break;
            }
        }
        if(rownum_left + rownum_right + 1 > 5){
            blackfiveplus++;
        }
        //再向45°-225°方向检索
        int rightup = 0;//右上连子数
        while(1){
            if(targetrow - rightup - 1 >= 0 && targetcol + rightup + 1 <= BOARDMAX && board[targetrow - rightup - 1][targetcol + rightup + 1] == BLACK){
                rightup ++;
            }
            else{
                break;
            }
        }
        int leftdown = 0;//左下连子数
        while(1){
            if(targetrow + leftdown + 1 <= BOARDMAX && targetcol - leftdown - 1 >= 0 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == BLACK){
                leftdown ++;
            }
            else{
                break;
            }
        }
        if(rightup + leftdown + 1 > 5){
            blackfiveplus++;
        }
        //再向135°-315°方向检索
        int rightdown = 0;//右下连子数
        while(1){
            if(targetrow + rightdown + 1 <= BOARDMAX && targetcol + rightdown + 1 <= BOARDMAX && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == BLACK){
                rightdown ++;
            }
            else{
                break;
            }
        }
        int leftup = 0;
        while(1){
            if(targetrow - leftup - 1 >= 0 && targetcol - leftup - 1 >= 0 && board[targetrow - leftup - 1][targetcol - leftup - 1] == BLACK){
                leftup ++;
            }
            else{
                break;
            }
        }
        if(rightdown + leftup + 1 > 5){
            blackfiveplus++;
        }
    }
    target = WHITE; //为了限制colnum_up等方向上连子数的作用域
    if(target == WHITE){//白棋检索
        //先纵向检索
        int colnum_up = 0;//向上连子数
        while(1){
            if(targetrow - colnum_up - 1 >= 0 && board[targetrow - colnum_up - 1][targetcol] == WHITE){
            colnum_up ++;
            }
            else{
                break;
            }
        }
        int colnum_down = 0;//向下连子数
        while(1){
            if(targetrow + colnum_down + 1 <= BOARDMAX && board[targetrow + colnum_down + 1][targetcol] == WHITE){
            colnum_down ++;
            }
            else{
                break;
            }
        }
        if(colnum_down + colnum_up + 1 > 5){
            whitefiveplus++;
        }
        //再横向检索
        int rownum_left = 0;//向左连子数
        while(1){
            if(targetcol - rownum_left - 1 >= 0 && board[targetrow][targetcol - rownum_left - 1] == WHITE){
            rownum_left ++;
            }
            else{
                break;
            }
        }
        int rownum_right = 0;//向右连子数
        while(1){
            if(targetcol + rownum_right + 1 <= BOARDMAX && board[targetrow][targetcol + rownum_right + 1] == WHITE){
                rownum_right ++;
            }
            else{
                break;
            }
        }
        if(rownum_left + rownum_right + 1 > 5){
           whitefiveplus++;
        }
        //再向45°-225°方向检索
        int rightup = 0;//右上连子数
        while(1){
            if(targetrow - rightup - 1 >= 0 && targetcol + rightup + 1 <= BOARDMAX && board[targetrow - rightup - 1][targetcol + rightup + 1] == WHITE){
                rightup ++;
            }
            else{
                break;
            }
        }
        int leftdown = 0;//左下连子数
        while(1){
            if(targetrow + leftdown + 1 <= BOARDMAX && targetcol - leftdown - 1 >= 0 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == WHITE){
                leftdown ++;
            }
            else{
                break;
            }
        }
        if(rightup + leftdown + 1 > 5){
            whitefiveplus++;
        }
        //再向135°-315°方向检索
        int rightdown = 0;//右下连子数
        while(1){
            if(targetrow + rightdown + 1 <= BOARDMAX && targetcol + rightdown + 1 <= BOARDMAX && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == WHITE){
                rightdown ++;
            }
            else{
                break;
            }
        }
        int leftup = 0;
        while(1){
            if(targetrow - leftup - 1 >= 0 && targetcol - leftup - 1 >= 0 && board[targetrow - leftup - 1][targetcol - leftup - 1] == WHITE){
                leftup ++;
            }
            else{
                break;
            }
        }
        if(rightdown + leftup + 1 > 5){
            whitefiveplus++;
        }
    }
}