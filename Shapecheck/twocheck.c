//关于二连的判断

#include<stdio.h>
#include"../gomoku.h"

int blacklivetwo;
int whitelivetwo;
int blacksleeptwo;
int whitesleeptwo;

void twocheck(int board[BOARDSIZE][BOARDSIZE],int targetrow,int targetcol){
    blacklivetwo = 0;
    whitelivetwo = 0;
    blacksleeptwo = 0;
    whitesleeptwo = 0;
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
            if(targetrow + colnum_down + 1 <= 14 && board[targetrow + colnum_down + 1][targetcol] == BLACK){
            colnum_down ++;
            }
            else{
                break;
            }
        }
        if(colnum_down + colnum_up + 1 == 2){
            if(targetrow != 0 && targetrow != 14 && targetrow + colnum_down != 14 && targetrow - colnum_up != 0 && board[targetrow + colnum_down + 1][targetcol] == EMPTY && board[targetrow - colnum_up - 1][targetcol] == EMPTY){
            blacklivetwo ++;
           }
           else{
            if(board[targetrow + colnum_down + 1][targetcol] == EMPTY && board[targetrow - colnum_up - 1][targetcol] == WHITE){
            blacksleeptwo ++;
           }
            else if(board[targetrow + colnum_down + 1][targetcol] == WHITE && board[targetrow - colnum_up - 1][targetcol] == EMPTY){
            blacksleeptwo ++;
           }
            else if(targetrow == 14 && board[targetrow - colnum_up - 1][targetcol] == EMPTY){
            blacksleeptwo ++;
           }
            else if(targetrow == 0 && board[targetrow + colnum_down + 1][targetcol] == EMPTY){
            blacksleeptwo ++;
           }
            else if(targetrow + colnum_down == 14 && board[targetrow - 1][targetcol] == EMPTY){
            blacksleeptwo ++;
            }
            else if(targetrow - colnum_up == 0 && board[targetrow + 1][targetcol] == EMPTY){
            blacksleeptwo ++;
            }
        }
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
            if(targetcol + rownum_right + 1 <= 14 && board[targetrow][targetcol + rownum_right + 1] == BLACK){
                rownum_right ++;
            }
            else{
                break;
            }
        }
        if(rownum_left + rownum_right + 1 == 2){
            if(targetcol != 0 && targetcol != 14 && targetcol + rownum_right != 14 && targetcol - rownum_left != 0 && board[targetrow][targetcol - rownum_left - 1] == EMPTY && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            blacklivetwo ++;
           }
            else{
            if(board[targetrow][targetcol - rownum_left - 1] == WHITE && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            blacksleeptwo ++;
           }
            else if(board[targetrow][targetcol - rownum_left - 1] == EMPTY && board[targetrow][targetcol + rownum_right + 1] == WHITE){
            blacksleeptwo ++;
           }
            else if(targetcol == 14 && board[targetrow][targetcol - rownum_left - 1] == EMPTY){
            blacksleeptwo ++;
           }
            else if(targetcol == 0 && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            blacksleeptwo ++;
           }
            else if(targetcol + rownum_right == 14 && board[targetrow][targetcol - 1] == EMPTY){
            blacksleeptwo ++;
            }
            else if(targetcol - rownum_left == 0 && board[targetrow][targetcol + 1] == EMPTY){
            blacksleeptwo ++;
            }
        }
        }
        //再向45°-225°方向检索
        int rightup = 0;//右上连子数
        while(1){
            if(targetrow - rightup - 1 >= 0 && targetcol + rightup + 1 <= 14 && board[targetrow - rightup - 1][targetcol + rightup + 1] == BLACK){
                rightup ++;
            }
            else{
                break;
            }
        }
        int leftdown = 0;//左下连子数
        while(1){
            if(targetrow + leftdown + 1 <= 14 && targetcol - leftdown - 1 >= 0 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == BLACK){
                leftdown ++;
            }
            else{
                break;
            }
        }
        if(rightup + leftdown + 1 == 2){
            if(targetcol != 0 && targetcol != 14 && targetrow != 0 && targetrow != 14 && targetrow + leftdown != 14 && targetrow - rightup != 0 && targetcol - leftdown != 0 && targetcol + rightup != 14 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            blacklivetwo ++;
           }
           else{
            if(board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY && board[targetrow - rightup - 1][targetcol + rightup + 1] == WHITE){
            blacksleeptwo ++;
           }
          else if(board[targetrow + leftdown + 1][targetcol - leftdown - 1] == WHITE && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            blacksleeptwo ++;
           }
           else if((targetcol == 14 || targetrow == 0) && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY){
            blacksleeptwo ++;
           }
            else if((targetcol == 0 || targetrow == 14) && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            blacksleeptwo ++;
        }
        else if((targetrow + leftdown == 14 || targetcol - leftdown == 0) && board[targetrow - 1][targetcol + 1] == EMPTY){
            blacksleeptwo ++;
            }
            else if((targetrow - rightup == 0 || targetcol + rightup == 14) && board[targetrow + 1][targetcol - 1] == EMPTY){
            blacksleeptwo ++;
            }
        }
        }
        //再向135°-315°方向检索
        int rightdown = 0;//右下连子数
        while(1){
            if(targetrow + rightdown + 1 <= 14 && targetcol + rightdown + 1 <= 14 && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == BLACK){
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
        if(rightdown + leftup + 1 == 2){
            if(targetcol != 0 && targetcol != 14 && targetrow != 0 && targetrow != 14 && targetrow + rightdown!= 14 && targetrow - leftup != 0 && targetcol + rightdown != 14 && targetcol - leftup != 0 && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            blacklivetwo ++;
           }
           else{
          if(board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY && board[targetrow - leftup - 1][targetcol - leftup - 1] == WHITE){
            blacksleeptwo ++;
           }
           else if(board[targetrow + rightdown + 1][targetcol + rightdown + 1] == WHITE && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            blacksleeptwo ++;
           }
           else if((targetcol == 14 || targetrow == 14) && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            blacksleeptwo ++;
           }
            else if((targetcol == 0 || targetrow == 0) && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY){
            blacksleeptwo ++;
        }
            else if((targetrow + rightdown == 14 || targetcol + rightdown == 14) && board[targetrow - 1][targetcol - 1] == EMPTY){
            blacksleeptwo ++;
            }
            else if((targetrow - leftup == 0 || targetcol - leftup == 0) && board[targetrow + 1][targetcol + 1] == EMPTY){
            blacksleeptwo ++;
            }
        }
        }
    }
    target = WHITE;
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
            if(targetrow + colnum_down + 1 <= 14 && board[targetrow + colnum_down + 1][targetcol] == WHITE){
            colnum_down ++;
            }
            else{
                break;
            }
        }
        if(colnum_down + colnum_up + 1 == 2){
           if(targetrow != 0 && targetrow != 14 && targetrow + colnum_down != 14 && targetrow - colnum_up != 0 && board[targetrow + colnum_down + 1][targetcol] == EMPTY && board[targetrow - colnum_up - 1][targetcol] == EMPTY){
            whitelivetwo ++;
           }
            else {
            if(board[targetrow + colnum_down + 1][targetcol] == EMPTY && board[targetrow - colnum_up - 1][targetcol] == BLACK){
            whitesleeptwo ++;
           }
           else if(board[targetrow + colnum_down + 1][targetcol] == BLACK && board[targetrow - colnum_up - 1][targetcol] == EMPTY){
            whitesleeptwo ++;
           }
           else if(targetrow == 14 && board[targetrow - colnum_up - 1][targetcol] == EMPTY){
            whitesleeptwo ++;
           }
            else if(targetrow == 0 && board[targetrow + colnum_down + 1][targetcol] == EMPTY){
            whitesleeptwo ++;
        }
            else if(targetrow + colnum_down == 14 && board[targetrow - 1][targetcol] == EMPTY){
            whitesleeptwo ++;
            }
            else if(targetrow - colnum_up == 0 && board[targetrow + 1][targetcol] == EMPTY){
            whitesleeptwo ++;
            }
    }
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
            if(targetcol + rownum_right + 1 <= 14 && board[targetrow][targetcol + rownum_right + 1] == WHITE){
                rownum_right ++;
            }
            else{
                break;
            }
        }
        if(rownum_left + rownum_right + 1 == 2){
            if(targetcol != 0 && targetcol != 14 && targetcol + rownum_right != 14 && targetcol - rownum_left != 0 && board[targetrow][targetcol - rownum_left - 1] == EMPTY && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            whitelivetwo ++;
           }
           else{
             if(board[targetrow][targetcol - rownum_left - 1] == BLACK && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            whitesleeptwo ++;
           }
            else if(board[targetrow][targetcol - rownum_left - 1] == EMPTY && board[targetrow][targetcol + rownum_right + 1] == BLACK){
            whitesleeptwo ++;
           }
           else if(targetcol == 14 && board[targetrow][targetcol - rownum_left - 1] == EMPTY){
            whitesleeptwo ++;
           }
           else if(targetcol == 0 && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            whitesleeptwo ++;
            }
            else if(targetcol + rownum_right == 14 && board[targetrow][targetcol - 1] == EMPTY){
            whitesleeptwo ++;
            }
            else if(targetcol - rownum_left == 0 && board[targetrow][targetcol + 1] == EMPTY){
            whitesleeptwo ++;
            }
        }
        }
        //再向45°-225°方向检索
        int rightup = 0;//右上连子数
        while(1){
            if(targetrow - rightup - 1 >= 0 && targetcol + rightup + 1 <= 14 && board[targetrow - rightup - 1][targetcol + rightup + 1] == WHITE){
                rightup ++;
            }
            else{
                break;
            }
        }
        int leftdown = 0;//左下连子数
        while(1){
            if(targetrow + leftdown + 1 <= 14 && targetcol - leftdown - 1 >= 0 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == WHITE){
                leftdown ++;
            }
            else{
                break;
            }
        }
        if(rightup + leftdown + 1 == 2){
            if(targetcol != 0 && targetcol != 14 && targetrow != 0 && targetrow != 14 && targetrow + leftdown != 14 && targetrow - rightup != 0 && targetcol - leftdown != 0 && targetcol + rightup != 14 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            whitelivetwo ++;
           }
           else{
          if(board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY && board[targetrow - rightup - 1][targetcol + rightup + 1] == BLACK){
            whitesleeptwo ++;
           }
           else if(board[targetrow + leftdown + 1][targetcol - leftdown - 1] == BLACK && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            whitesleeptwo ++;
           }
           else if((targetcol == 14 || targetrow == 0) && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY){
            whitesleeptwo ++;
           }
            else if((targetcol == 0 || targetrow == 14) && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            whitesleeptwo ++;
        }
          else if((targetrow + leftdown == 14 || targetcol - leftdown == 0) && board[targetrow - 1][targetcol + 1] == EMPTY){
            whitesleeptwo ++;
            }
            else if((targetrow - rightup == 0 || targetcol + rightup == 14) && board[targetrow + 1][targetcol - 1] == EMPTY){
            whitesleeptwo ++;
            }
        }
        }
        //再向135°-315°方向检索
        int rightdown = 0;//右下连子数
        while(1){
            if(targetrow + rightdown + 1 <= 14 && targetcol + rightdown + 1 <= 14 && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == WHITE){
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
        if(rightdown + leftup + 1 == 2){
            if(targetcol != 0 && targetcol != 14 && targetrow != 0 && targetrow != 14 && targetrow + rightdown!= 14 && targetrow - leftup != 0 && targetcol + rightdown != 14 && targetcol - leftup != 0 && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            whitelivetwo ++;
           }
           else {
            if(board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY && board[targetrow - leftup - 1][targetcol - leftup - 1] == BLACK){
            whitesleeptwo ++;
           }
           else if(board[targetrow + rightdown + 1][targetcol + rightdown + 1] == BLACK && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            whitesleeptwo ++;
           }
            else if((targetcol == 14 || targetrow == 14) && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            whitesleeptwo ++;
           }
             else if((targetcol == 0 || targetrow == 0) && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY){
            whitesleeptwo ++;
        }
        else if((targetrow + rightdown == 14 || targetcol + rightdown == 14) && board[targetrow - 1][targetcol - 1] == EMPTY){
            whitesleeptwo ++;
            }
            else if((targetrow - leftup == 0 || targetcol - leftup == 0) && board[targetrow + 1][targetcol + 1] == EMPTY){
            whitesleeptwo ++;
            }
        }
        }
    }
}