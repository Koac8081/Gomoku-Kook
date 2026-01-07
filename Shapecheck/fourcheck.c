//检查下在此处是否能形成活四,冲四

#include<stdio.h>
#include"../gomoku.h"

int blacklivefour = 0;
int whitelivefour = 0;

int blackchargefour = 0;
int whitechargefour = 0;

void fourcheck(int board[BOARDSIZE][BOARDSIZE],int targetrow,int targetcol){
    blacklivefour = 0;
    whitelivefour = 0;
    blackchargefour = 0;
    whitechargefour = 0;
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
        if(colnum_down + colnum_up + 1 == 4){
            if(targetrow != 0 && targetrow != 14 && targetrow + colnum_down != 14 && targetrow - colnum_up != 0 && board[targetrow + colnum_down + 1][targetcol] == EMPTY && board[targetrow - colnum_up - 1][targetcol] == EMPTY){
            blacklivefour ++;
           }
           else{
            if(board[targetrow + colnum_down + 1][targetcol] == EMPTY && board[targetrow - colnum_up - 1][targetcol] == WHITE){
            blackchargefour ++;
           }
            else if(board[targetrow + colnum_down + 1][targetcol] == WHITE && board[targetrow - colnum_up - 1][targetcol] == EMPTY){
            blackchargefour ++;
           }
            else if(targetrow == 14 && board[targetrow - colnum_up - 1][targetcol] == EMPTY){
            blackchargefour ++;
           }
            else if(targetrow == 0 && board[targetrow + colnum_down + 1][targetcol] == EMPTY){
            blackchargefour ++;
           }
            else if(targetrow + colnum_down == 14 && board[targetrow - 1][targetcol] == EMPTY){
            blackchargefour ++;
            }
            else if(targetrow - colnum_up == 0 && board[targetrow + 1][targetcol] == EMPTY){
            blackchargefour ++;
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
        if(rownum_left + rownum_right + 1 == 4){
            if(targetcol != 0 && targetcol != 14 && targetcol + rownum_right != 14 && targetcol - rownum_left != 0 && board[targetrow][targetcol - rownum_left - 1] == EMPTY && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            blacklivefour ++;
           }
            else{
            if(board[targetrow][targetcol - rownum_left - 1] == WHITE && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            blackchargefour ++;
           }
            else if(board[targetrow][targetcol - rownum_left - 1] == EMPTY && board[targetrow][targetcol + rownum_right + 1] == WHITE){
            blackchargefour ++;
           }
            else if(targetcol == 14 && board[targetrow][targetcol - rownum_left - 1] == EMPTY){
            blackchargefour ++;
           }
            else if(targetcol == 0 && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            blackchargefour ++;
           }
            else if(targetcol + rownum_right == 14 && board[targetrow][targetcol - 1] == EMPTY){
            blackchargefour ++;
            }
            else if(targetcol - rownum_left == 0 && board[targetrow][targetcol + 1] == EMPTY){
            blackchargefour ++;
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
        if(rightup + leftdown + 1 == 4){
            if(targetcol != 0 && targetcol != 14 && targetrow != 0 && targetrow != 14 && targetrow + leftdown != 14 && targetrow - rightup != 0 && targetcol - leftdown != 0 && targetcol + rightup != 14 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            blacklivefour ++;
           }
           else{
            if(board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY && board[targetrow - rightup - 1][targetcol + rightup + 1] == WHITE){
            blackchargefour ++;
           }
          else if(board[targetrow + leftdown + 1][targetcol - leftdown - 1] == WHITE && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            blackchargefour ++;
           }
           else if((targetcol == 14 || targetrow == 0) && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY){
            blackchargefour ++;
           }
            else if((targetcol == 0 || targetrow == 14) && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            blackchargefour ++;
        }
        else if((targetrow + leftdown == 14 || targetcol - leftdown == 0) && board[targetrow - 1][targetcol + 1] == EMPTY){
            blackchargefour ++;
            }
            else if((targetrow - rightup == 0 || targetcol + rightup == 14) && board[targetrow + 1][targetcol - 1] == EMPTY){
            blackchargefour ++;
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
        if(rightdown + leftup + 1 == 4){
            if(targetcol != 0 && targetcol != 14 && targetrow != 0 && targetrow != 14 && targetrow + rightdown!= 14 && targetrow - leftup != 0 && targetcol + rightdown != 14 && targetcol - leftup != 0 && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            blacklivefour ++;
           }
           else{
          if(board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY && board[targetrow - leftup - 1][targetcol - leftup - 1] == WHITE){
            blackchargefour ++;
           }
           else if(board[targetrow + rightdown + 1][targetcol + rightdown + 1] == WHITE && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            blackchargefour ++;
           }
           else if((targetcol == 14 || targetrow == 14) && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            blackchargefour ++;
           }
            else if((targetcol == 0 || targetrow == 0) && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY){
            blackchargefour ++;
        }
            else if((targetrow + rightdown == 14 || targetcol + rightdown == 14) && board[targetrow - 1][targetcol - 1] == EMPTY){
            blackchargefour ++;
            }
            else if((targetrow - leftup == 0 || targetcol - leftup == 0) && board[targetrow + 1][targetcol + 1] == EMPTY){
            blackchargefour ++;
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
        if(colnum_down + colnum_up + 1 == 4){
           if(targetrow != 0 && targetrow != 14 && targetrow + colnum_down != 14 && targetrow - colnum_up != 0 && board[targetrow + colnum_down + 1][targetcol] == EMPTY && board[targetrow - colnum_down - 1][targetcol] == EMPTY){
            whitelivefour ++;
           }
            else {
            if(board[targetrow + colnum_down + 1][targetcol] == EMPTY && board[targetrow - colnum_down - 1][targetcol] == BLACK){
            whitechargefour ++;
           }
           else if(board[targetrow + colnum_down + 1][targetcol] == BLACK && board[targetrow - colnum_down - 1][targetcol] == EMPTY){
            whitechargefour ++;
           }
           else if(targetrow == 14 && board[targetrow - colnum_down - 1][targetcol] == EMPTY){
            whitechargefour ++;
           }
            else if(targetrow == 0 && board[targetrow + colnum_down + 1][targetcol] == EMPTY){
            whitechargefour ++;
        }
            else if(targetrow + colnum_down == 14 && board[targetrow - 1][targetcol] == EMPTY){
            whitechargefour ++;
            }
            else if(targetrow - colnum_down == 0 && board[targetrow + 1][targetcol] == EMPTY){
            whitechargefour ++;
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
        if(rownum_left + rownum_right + 1 == 4){
            if(targetcol != 0 && targetcol != 14 && targetcol + rownum_right != 14 && targetcol - rownum_left != 0 && board[targetrow][targetcol - rownum_left - 1] == EMPTY && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            whitelivefour ++;
           }
           else{
             if(board[targetrow][targetcol - rownum_left - 1] == BLACK && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            whitechargefour ++;
           }
            else if(board[targetrow][targetcol - rownum_left - 1] == EMPTY && board[targetrow][targetcol + rownum_right + 1] == BLACK){
            whitechargefour ++;
           }
           else if(targetcol == 14 && board[targetrow][targetcol - rownum_left - 1] == EMPTY){
            whitechargefour ++;
           }
           else if(targetcol == 0 && board[targetrow][targetcol + rownum_right + 1] == EMPTY){
            whitechargefour ++;
            }
            else if(targetcol + rownum_right == 14 && board[targetrow][targetcol - 1] == EMPTY){
            whitechargefour ++;
            }
            else if(targetcol - rownum_left == 0 && board[targetrow][targetcol + 1] == EMPTY){
            whitechargefour ++;
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
        if(rightup + leftdown + 1 == 4){
            if(targetcol != 0 && targetcol != 14 && targetrow != 0 && targetrow != 14 && targetrow + leftdown != 14 && targetrow - rightup != 0 && targetcol - leftdown != 0 && targetcol + rightup != 14 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            whitelivefour ++;
           }
           else{
          if(board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY && board[targetrow - rightup - 1][targetcol + rightup + 1] == BLACK){
            whitechargefour ++;
           }
           else if(board[targetrow + leftdown + 1][targetcol - leftdown - 1] == BLACK && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            whitechargefour ++;
           }
           else if((targetcol == 14 || targetrow == 0) && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY){
            whitechargefour ++;
           }
            else if((targetcol == 0 || targetrow == 14) && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY){
            whitechargefour ++;
        }
          else if((targetrow + leftdown == 14 || targetcol - leftdown == 0) && board[targetrow - 1][targetcol + 1] == EMPTY){
            whitechargefour ++;
            }
            else if((targetrow - rightup == 0 || targetcol + rightup == 14) && board[targetrow + 1][targetcol - 1] == EMPTY){
            whitechargefour ++;
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
        if(rightdown + leftup + 1 == 4){
            if(targetcol != 0 && targetcol != 14 && targetrow != 0 && targetrow != 14 && targetrow + rightdown!= 14 && targetrow - leftup != 0 && targetcol + rightdown != 14 && targetcol - leftup != 0 && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            whitelivefour ++;
           }
           else {
            if(board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY && board[targetrow - leftup - 1][targetcol - leftup - 1] == BLACK){
            whitechargefour ++;
           }
           else if(board[targetrow + rightdown + 1][targetcol + rightdown + 1] == BLACK && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            whitechargefour ++;
           }
            else if((targetcol == 14 || targetrow == 14) && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY){
            whitechargefour ++;
           }
             else if((targetcol == 0 || targetrow == 0) && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY){
            whitechargefour ++;
        }
        else if((targetrow + rightdown == 14 || targetcol + rightdown == 14) && board[targetrow - 1][targetcol - 1] == EMPTY){
            whitechargefour ++;
            }
            else if((targetrow - leftup == 0 || targetcol - leftup == 0) && board[targetrow + 1][targetcol + 1] == EMPTY){
            whitechargefour ++;
            }
        }
        }
    }
}