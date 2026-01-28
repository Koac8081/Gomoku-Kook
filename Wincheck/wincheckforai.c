//为决策树使用的wincheck

#include"../gomoku.h"

int wincheckforai(int board[BOARDSIZE][BOARDSIZE],int goinger,int row,int col){//此函数目前没有参与实际程序
    if(goinger == BLACKGO){//黑棋下完一步后，检索是否胜利；只检查goinger一方，避免重复
        //先纵向检索
        int colnum_up = 0;//向上连子数
        while(1){
            if(row - colnum_up - 1 >= 0 && board[row - colnum_up - 1][col] == BLACK){
            colnum_up ++;
            }
            else{//五连或长连必然是同色紧贴，检测到不是黑色中断即可
                break;
            }
        }
        int colnum_down = 0;//向下连子数
        while(1){
            if(row + colnum_down + 1 <= 14 && board[row + colnum_down + 1][col] == BLACK){
            colnum_down ++;
            }
            else{
                break;
            }
        }
        if(colnum_down + colnum_up + 1 == 5){
            return BLACKWIN;//黑棋长连为禁手
        }
        //再横向检索
        int rownum_left = 0;//向左连子数
        while(1){
            if(col - rownum_left - 1 >= 0 && board[row][col - rownum_left - 1] == BLACK){
            rownum_left ++;
            }
            else{
                break;
            }
        }
        int rownum_right = 0;//向右连子数
        while(1){
            if(col + rownum_right + 1 <= 14 && board[row][col + rownum_right + 1] == BLACK){
                rownum_right ++;
            }
            else{
                break;
            }
        }
        if(rownum_left + rownum_right + 1 == 5){
            return BLACKWIN;
        }
        //再向45°-225°方向检索
        int rightup = 0;//右上连子数
        while(1){
            if(row - rightup - 1 >= 0 && col + rightup + 1 <= 14 && board[row - rightup - 1][col + rightup + 1] == BLACK){
                rightup ++;
            }
            else{
                break;
            }
        }
        int leftdown = 0;//左下连子数
        while(1){
            if(row + leftdown + 1 <= 14 && col - leftdown - 1 >= 0 && board[row + leftdown + 1][col - leftdown - 1] == BLACK){
                leftdown ++;
            }
            else{
                break;
            }
        }
        if(rightup + leftdown + 1 == 5){
            return BLACKWIN;
        }
        //再向135°-315°方向检索
        int rightdown = 0;//右下连子数
        while(1){
            if(row + rightdown + 1 <= 14 && col + rightdown + 1 <= 14 && board[row + rightdown + 1][col + rightdown + 1] == BLACK){
                rightdown ++;
            }
            else{
                break;
            }
        }
        int leftup = 0;
        while(1){
            if(row - leftup - 1 >= 0 && col - leftup - 1 >= 0 && board[row - leftup - 1][col - leftup - 1] == BLACK){
                leftup ++;
            }
            else{
                break;
            }
        }
        if(rightdown + leftup + 1 == 5){
            return BLACKWIN;
        }
    }
    else if(goinger == WHITEGO){//白棋下完一步后，检索是否胜利
        //先纵向检索
        int colnum_up = 0;//向上连子数
        while(1){
            if(row - colnum_up - 1 >= 0 && board[row - colnum_up - 1][col] == WHITE){
            colnum_up ++;
            }
            else{
                break;
            }
        }
        int colnum_down = 0;//向下连子数
        while(1){
            if(row + colnum_down + 1 <= 14 && board[row + colnum_down + 1][col] == WHITE){
            colnum_down ++;
            }
            else{
                break;
            }
        }
        if(colnum_down + colnum_up + 1 >= 5){
            return WHITEWIN;
        }
        //再横向检索
        int rownum_left = 0;//向左连子数
        while(1){
            if(col - rownum_left - 1 >= 0 && board[row][col - rownum_left - 1] == WHITE){
            rownum_left ++;
            }
            else{
                break;
            }
        }
        int rownum_right = 0;//向右连子数
        while(1){
            if(col + rownum_right + 1 <= 14 && board[row][col + rownum_right + 1] == WHITE){
                rownum_right ++;
            }
            else{
                break;
            }
        }
        if(rownum_left + rownum_right + 1 >= 5){
            return WHITEWIN;
        }
        //再向45°-225°方向检索
        int rightup = 0;//右上连子数
        while(1){
            if(row - rightup - 1 >= 0 && col + rightup + 1 <= 14 && board[row - rightup - 1][col + rightup + 1] == WHITE){
                rightup ++;
            }
            else{
                break;
            }
        }
        int leftdown = 0;//左下连子数
        while(1){
            if(row + leftdown + 1 <= 14 && col - leftdown - 1 >= 0 && board[row + leftdown + 1][col - leftdown - 1] == WHITE){
                leftdown ++;
            }
            else{
                break;
            }
        }
        if(rightup + leftdown + 1 >= 5){
            return WHITEWIN;
        }
        //再向135°-315°方向检索
        int rightdown = 0;//右下连子数
        while(1){
            if(row + rightdown + 1 <= 14 && col + rightdown + 1 <= 14 && board[row + rightdown + 1][col + rightdown + 1] == WHITE){
                rightdown ++;
            }
            else{
                break;
            }
        }
        int leftup = 0;
        while(1){
            if(row - leftup - 1 >= 0 && col - leftup - 1 >= 0 && board[row - leftup - 1][col - leftup - 1] == WHITE){
                leftup ++;
            }
            else{
                break;
            }
        }
        if(rightdown + leftup + 1 >= 5){
            return WHITEWIN;
        }
    }
    return UNDERWAY;
}