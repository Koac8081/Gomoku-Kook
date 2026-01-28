//检查是否有一方胜利或平局

#include"../gomoku.h"

void wincheck(int board[BOARDSIZE][BOARDSIZE],int goinger,int row,char col,int blackstep,int whitestep){
    int realrow = BOARDSIZE - row;
    int realcol = col - 'A';
    if(goinger == BLACKGO && blackstep + whitestep < 225){//黑棋下完一步后，检索是否胜利；只检查goinger一方，避免重复
        //先纵向检索
        int colnum_up = 0;//向上连子数
        while(1){
            if(realrow - colnum_up - 1 >= 0 && board[realrow - colnum_up - 1][realcol] == BLACK){
            colnum_up ++;
            }
            else{//五连或长连必然是同色紧贴，检测到不是黑色中断即可
                break;
            }
        }
        int colnum_down = 0;//向下连子数
        while(1){
            if(realrow + colnum_down + 1 <= 14 && board[realrow + colnum_down + 1][realcol] == BLACK){
            colnum_down ++;
            }
            else{
                break;
            }
        }
        if(colnum_down + colnum_up + 1 == 5){
            gamestate = BLACKWIN;//黑棋长连为禁手
        }
        //再横向检索
        int rownum_left = 0;//向左连子数
        while(1){
            if(realcol - rownum_left - 1 >= 0 && board[realrow][realcol - rownum_left - 1] == BLACK){
            rownum_left ++;
            }
            else{
                break;
            }
        }
        int rownum_right = 0;//向右连子数
        while(1){
            if(realcol + rownum_right + 1 <= 14 && board[realrow][realcol + rownum_right + 1] == BLACK){
                rownum_right ++;
            }
            else{
                break;
            }
        }
        if(rownum_left + rownum_right + 1 == 5){
            gamestate = BLACKWIN;
        }
        //再向45°-225°方向检索
        int rightup = 0;//右上连子数
        while(1){
            if(realrow - rightup - 1 >= 0 && realcol + rightup + 1 <= 14 && board[realrow - rightup - 1][realcol + rightup + 1] == BLACK){
                rightup ++;
            }
            else{
                break;
            }
        }
        int leftdown = 0;//左下连子数
        while(1){
            if(realrow + leftdown + 1 <= 14 && realcol - leftdown - 1 >= 0 && board[realrow + leftdown + 1][realcol - leftdown - 1] == BLACK){
                leftdown ++;
            }
            else{
                break;
            }
        }
        if(rightup + leftdown + 1 == 5){
            gamestate = BLACKWIN;
        }
        //再向135°-315°方向检索
        int rightdown = 0;//右下连子数
        while(1){
            if(realrow + rightdown + 1 <= 14 && realcol + rightdown + 1 <= 14 && board[realrow + rightdown + 1][realcol + rightdown + 1] == BLACK){
                rightdown ++;
            }
            else{
                break;
            }
        }
        int leftup = 0;
        while(1){
            if(realrow - leftup - 1 >= 0 && realcol - leftup - 1 >= 0 && board[realrow - leftup - 1][realcol - leftup - 1] == BLACK){
                leftup ++;
            }
            else{
                break;
            }
        }
        if(rightdown + leftup + 1 == 5){
            gamestate = BLACKWIN;
        }
    }
    else if(goinger == WHITEGO && blackstep + whitestep < 225){//白棋下完一步后，检索是否胜利
        //先纵向检索
        int colnum_up = 0;//向上连子数
        while(1){
            if(realrow - colnum_up - 1 >= 0 && board[realrow - colnum_up - 1][realcol] == WHITE){
            colnum_up ++;
            }
            else{
                break;
            }
        }
        int colnum_down = 0;//向下连子数
        while(1){
            if(realrow + colnum_down + 1 <= 14 && board[realrow + colnum_down + 1][realcol] == WHITE){
            colnum_down ++;
            }
            else{
                break;
            }
        }
        if(colnum_down + colnum_up + 1 >= 5){
            gamestate = WHITEWIN;
        }
        //再横向检索
        int rownum_left = 0;//向左连子数
        while(1){
            if(realcol - rownum_left - 1 >= 0 && board[realrow][realcol - rownum_left - 1] == WHITE){
            rownum_left ++;
            }
            else{
                break;
            }
        }
        int rownum_right = 0;//向右连子数
        while(1){
            if(realcol + rownum_right + 1 <= 14 && board[realrow][realcol + rownum_right + 1] == WHITE){
                rownum_right ++;
            }
            else{
                break;
            }
        }
        if(rownum_left + rownum_right + 1 >= 5){
            gamestate = WHITEWIN;
        }
        //再向45°-225°方向检索
        int rightup = 0;//右上连子数
        while(1){
            if(realrow - rightup - 1 >= 0 && realcol + rightup + 1 <= 14 && board[realrow - rightup - 1][realcol + rightup + 1] == WHITE){
                rightup ++;
            }
            else{
                break;
            }
        }
        int leftdown = 0;//左下连子数
        while(1){
            if(realrow + leftdown + 1 <= 14 && realcol - leftdown - 1 >= 0 && board[realrow + leftdown + 1][realcol - leftdown - 1] == WHITE){
                leftdown ++;
            }
            else{
                break;
            }
        }
        if(rightup + leftdown + 1 >= 5){
            gamestate = WHITEWIN;
        }
        //再向135°-315°方向检索
        int rightdown = 0;//右下连子数
        while(1){
            if(realrow + rightdown + 1 <= 14 && realcol + rightdown + 1 <= 14 && board[realrow + rightdown + 1][realcol + rightdown + 1] == WHITE){
                rightdown ++;
            }
            else{
                break;
            }
        }
        int leftup = 0;
        while(1){
            if(realrow - leftup - 1 >= 0 && realcol - leftup - 1 >= 0 && board[realrow - leftup - 1][realcol - leftup - 1] == WHITE){
                leftup ++;
            }
            else{
                break;
            }
        }
        if(rightdown + leftup + 1 >= 5){
            gamestate = WHITEWIN;
        }
    }
    else if(blackstep + whitestep == MAXSTEP){
        gamestate = PEACE;//棋盘下满，判平局
    }
}