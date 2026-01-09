// 关于二连的判断
#include <stdio.h>
#include "../gomoku.h"

int blacklivetwo;
int whitelivetwo;
int blacksleeptwo;
int whitesleeptwo;

void twocheck(int board[BOARDSIZE][BOARDSIZE], int targetrow, int targetcol) {
    blacklivetwo = 0;
    whitelivetwo = 0;
    blacksleeptwo = 0;
    whitesleeptwo = 0;

    // 黑棋检索
    // 纵向检索
    int colnum_up = 0;
    while (1) {
        if (targetrow - colnum_up - 1 >= 0 && board[targetrow - colnum_up - 1][targetcol] == BLACK) {
            colnum_up++;
        }
        else {
            break;
        }
    }
    int colnum_down = 0;
    while (1) {
        if (targetrow + colnum_down + 1 <= BOARDMAX && board[targetrow + colnum_down + 1][targetcol] == BLACK) {
            colnum_down++;
        }
        else {
            break;
        }
    }

    if (colnum_down + colnum_up + 1 == 2) {
        if (targetrow - colnum_up > 0 && targetrow + colnum_down < BOARDMAX &&
            board[targetrow - colnum_up - 1][targetcol] == EMPTY &&
            board[targetrow + colnum_down + 1][targetcol] == EMPTY) {
            blacklivetwo++;
        }
        else {
            if (targetrow - colnum_up > 0 && board[targetrow - colnum_up - 1][targetcol] == EMPTY) {
                blacksleeptwo++;
            }
            else if (targetrow + colnum_down < BOARDMAX && board[targetrow + colnum_down + 1][targetcol] == EMPTY) {
                blacksleeptwo++;
            }
        }
    }
    else if (colnum_down + colnum_up + 1 == 1) { // 跳二判断
        if (targetrow - 2 >= 0 && board[targetrow - 1][targetcol] == EMPTY && board[targetrow - 2][targetcol] == BLACK) {
            blacksleeptwo++;
        }
        if (targetrow + 2 <= BOARDMAX && board[targetrow + 1][targetcol] == EMPTY && board[targetrow + 2][targetcol] == BLACK) {
            blacksleeptwo++;
        }
    }

    // 横向检索
    int rownum_left = 0;
    while (1) {
        if (targetcol - rownum_left - 1 >= 0 && board[targetrow][targetcol - rownum_left - 1] == BLACK) {
            rownum_left++;
        }
        else {
            break;
        }
    }
    int rownum_right = 0;
    while (1) {
        if (targetcol + rownum_right + 1 <= BOARDMAX && board[targetrow][targetcol + rownum_right + 1] == BLACK) {
            rownum_right++;
        }
        else {
            break;
        }
    }

    if (rownum_left + rownum_right + 1 == 2) {
        if (targetcol - rownum_left > 0 && targetcol + rownum_right < BOARDMAX &&
            board[targetrow][targetcol - rownum_left - 1] == EMPTY &&
            board[targetrow][targetcol + rownum_right + 1] == EMPTY) {
            blacklivetwo++;
        }
        else {
            if (targetcol - rownum_left > 0 && board[targetrow][targetcol - rownum_left - 1] == EMPTY) {
                blacksleeptwo++;
            }
            else if (targetcol + rownum_right < BOARDMAX && board[targetrow][targetcol + rownum_right + 1] == EMPTY) {
                blacksleeptwo++;
            }
        }
    }
    else if (rownum_left + rownum_right + 1 == 1) {
        if (targetcol - 2 >= 0 && board[targetrow][targetcol - 1] == EMPTY && board[targetrow][targetcol - 2] == BLACK) {
            blacksleeptwo++;
        }
        if (targetcol + 2 <= BOARDMAX && board[targetrow][targetcol + 1] == EMPTY && board[targetrow][targetcol + 2] == BLACK) {
            blacksleeptwo++;
        }
    }

    // 45°方向
    int rightup = 0;
    while (1) {
        if (targetrow - rightup - 1 >= 0 && targetcol + rightup + 1 <= BOARDMAX && board[targetrow - rightup - 1][targetcol + rightup + 1] == BLACK) {
            rightup++;
        }
        else {
            break;
        }
    }
    int leftdown = 0;
    while (1) {
        if (targetrow + leftdown + 1 <= BOARDMAX && targetcol - leftdown - 1 >= 0 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == BLACK) {
            leftdown++;
        }
        else {
            break;
        }
    }

    if (rightup + leftdown + 1 == 2) {
        if (targetrow - rightup > 0 && targetcol + rightup < BOARDMAX &&
            targetrow + leftdown < BOARDMAX && targetcol - leftdown > 0 &&
            board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY &&
            board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY) {
            blacklivetwo++;
        }
        else {
            if (targetrow - rightup > 0 && targetcol + rightup < BOARDMAX && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY) {
                blacksleeptwo++;
            }
            else if (targetrow + leftdown < BOARDMAX && targetcol - leftdown > 0 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY) {
                blacksleeptwo++;
            }
        }
    }
    else if (rightup + leftdown + 1 == 1) {
        if (targetrow - 2 >= 0 && targetcol + 2 <= BOARDMAX && board[targetrow - 1][targetcol + 1] == EMPTY && board[targetrow - 2][targetcol + 2] == BLACK) {
            blacksleeptwo++;
        }
        if (targetrow + 2 <= BOARDMAX && targetcol - 2 >= 0 && board[targetrow + 1][targetcol - 1] == EMPTY && board[targetrow + 2][targetcol - 2] == BLACK) {
            blacksleeptwo++;
        }
    }

    // 135°方向
    int rightdown = 0;
    while (1) {
        if (targetrow + rightdown + 1 <= BOARDMAX && targetcol + rightdown + 1 <= BOARDMAX && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == BLACK) {
            rightdown++;
        }
        else {
            break;
        }
    }
    int leftup = 0;
    while (1) {
        if (targetrow - leftup - 1 >= 0 && targetcol - leftup - 1 >= 0 && board[targetrow - leftup - 1][targetcol - leftup - 1] == BLACK) {
            leftup++;
        }
        else {
            break;
        }
    }

    if (rightdown + leftup + 1 == 2) {
        if (targetrow + rightdown < BOARDMAX && targetcol + rightdown < BOARDMAX &&
            targetrow - leftup > 0 && targetcol - leftup > 0 &&
            board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY &&
            board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY) {
            blacklivetwo++;
        }
        else {
            if (targetrow + rightdown < BOARDMAX && targetcol + rightdown < BOARDMAX && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY) {
                blacksleeptwo++;
            }
            else if (targetrow - leftup > 0 && targetcol - leftup > 0 && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY) {
                blacksleeptwo++;
            }
        }
    }
    else if (rightdown + leftup + 1 == 1) {
        if (targetrow + 2 <= BOARDMAX && targetcol + 2 <= BOARDMAX && board[targetrow + 1][targetcol + 1] == EMPTY && board[targetrow + 2][targetcol + 2] == BLACK) {
            blacksleeptwo++;
        }
        if (targetrow - 2 >= 0 && targetcol - 2 >= 0 && board[targetrow - 1][targetcol - 1] == EMPTY && board[targetrow - 2][targetcol - 2] == BLACK) {
            blacksleeptwo++;
        }
    }

    // 白棋检索
    // 纵向检索
    colnum_up = 0;
    while (1) {
        if (targetrow - colnum_up - 1 >= 0 && board[targetrow - colnum_up - 1][targetcol] == WHITE) {
            colnum_up++;
        }
        else {
            break;
        }
    }
    colnum_down = 0;
    while (1) {
        if (targetrow + colnum_down + 1 <= BOARDMAX && board[targetrow + colnum_down + 1][targetcol] == WHITE) {
            colnum_down++;
        }
        else {
            break;
        }
    }

    if (colnum_down + colnum_up + 1 == 2) {
        if (targetrow - colnum_up > 0 && targetrow + colnum_down < BOARDMAX &&
            board[targetrow - colnum_up - 1][targetcol] == EMPTY &&
            board[targetrow + colnum_down + 1][targetcol] == EMPTY) {
            whitelivetwo++;
        }
        else {
            if (targetrow - colnum_up > 0 && board[targetrow - colnum_up - 1][targetcol] == EMPTY) {
                whitesleeptwo++;
            }
            else if (targetrow + colnum_down < BOARDMAX && board[targetrow + colnum_down + 1][targetcol] == EMPTY) {
                whitesleeptwo++;
            }
        }
    }
    else if (colnum_down + colnum_up + 1 == 1) {
        if (targetrow - 2 >= 0 && board[targetrow - 1][targetcol] == EMPTY && board[targetrow - 2][targetcol] == WHITE) {
            whitesleeptwo++;
        }
        if (targetrow + 2 <= BOARDMAX && board[targetrow + 1][targetcol] == EMPTY && board[targetrow + 2][targetcol] == WHITE) {
            whitesleeptwo++;
        }
    }

    // 横向检索
    rownum_left = 0;
    while (1) {
        if (targetcol - rownum_left - 1 >= 0 && board[targetrow][targetcol - rownum_left - 1] == WHITE) {
            rownum_left++;
        }
        else {
            break;
        }
    }
    rownum_right = 0;
    while (1) {
        if (targetcol + rownum_right + 1 <= BOARDMAX && board[targetrow][targetcol + rownum_right + 1] == WHITE) {
            rownum_right++;
        }
        else {
            break;
        }
    }

    if (rownum_left + rownum_right + 1 == 2) {
        if (targetcol - rownum_left > 0 && targetcol + rownum_right < BOARDMAX &&
            board[targetrow][targetcol - rownum_left - 1] == EMPTY &&
            board[targetrow][targetcol + rownum_right + 1] == EMPTY) {
            whitelivetwo++;
        }
        else {
            if (targetcol - rownum_left > 0 && board[targetrow][targetcol - rownum_left - 1] == EMPTY) {
                whitesleeptwo++;
            }
            else if (targetcol + rownum_right < BOARDMAX && board[targetrow][targetcol + rownum_right + 1] == EMPTY) {
                whitesleeptwo++;
            }
        }
    }
    else if (rownum_left + rownum_right + 1 == 1) {
        if (targetcol - 2 >= 0 && board[targetrow][targetcol - 1] == EMPTY && board[targetrow][targetcol - 2] == WHITE) {
            whitesleeptwo++;
        }
        if (targetcol + 2 <= BOARDMAX && board[targetrow][targetcol + 1] == EMPTY && board[targetrow][targetcol + 2] == WHITE) {
            whitesleeptwo++;
        }
    }

    // 45°方向
    rightup = 0;
    while (1) {
        if (targetrow - rightup - 1 >= 0 && targetcol + rightup + 1 <= BOARDMAX && board[targetrow - rightup - 1][targetcol + rightup + 1] == WHITE) {
            rightup++;
        }
        else {
            break;
        }
    }
    leftdown = 0;
    while (1) {
        if (targetrow + leftdown + 1 <= BOARDMAX && targetcol - leftdown - 1 >= 0 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == WHITE) {
            leftdown++;
        }
        else {
            break;
        }
    }

    if (rightup + leftdown + 1 == 2) {
        if (targetrow - rightup > 0 && targetcol + rightup < BOARDMAX &&
            targetrow + leftdown < BOARDMAX && targetcol - leftdown > 0 &&
            board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY &&
            board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY) {
            whitelivetwo++;
        }
        else {
            if (targetrow - rightup > 0 && targetcol + rightup < BOARDMAX && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY) {
                whitesleeptwo++;
            }
            else if (targetrow + leftdown < BOARDMAX && targetcol - leftdown > 0 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY) {
                whitesleeptwo++;
            }
        }
    }
    else if (rightup + leftdown + 1 == 1) {
        if (targetrow - 2 >= 0 && targetcol + 2 <= BOARDMAX && board[targetrow - 1][targetcol + 1] == EMPTY && board[targetrow - 2][targetcol + 2] == WHITE) {
            whitesleeptwo++;
        }
        if (targetrow + 2 <= BOARDMAX && targetcol - 2 >= 0 && board[targetrow + 1][targetcol - 1] == EMPTY && board[targetrow + 2][targetcol - 2] == WHITE) {
            whitesleeptwo++;
        }
    }

    // 135°方向
    rightdown = 0;
    while (1) {
        if (targetrow + rightdown + 1 <= BOARDMAX && targetcol + rightdown + 1 <= BOARDMAX && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == WHITE) {
            rightdown++;
        }
        else {
            break;
        }
    }
    leftup = 0;
    while (1) {
        if (targetrow - leftup - 1 >= 0 && targetcol - leftup - 1 >= 0 && board[targetrow - leftup - 1][targetcol - leftup - 1] == WHITE) {
            leftup++;
        }
        else {
            break;
        }
    }

    if (rightdown + leftup + 1 == 2) {
        if (targetrow + rightdown < BOARDMAX && targetcol + rightdown < BOARDMAX &&
            targetrow - leftup > 0 && targetcol - leftup > 0 &&
            board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY &&
            board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY) {
            whitelivetwo++;
        }
        else {
            if (targetrow + rightdown < BOARDMAX && targetcol + rightdown < BOARDMAX && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY) {
                whitesleeptwo++;
            }
            else if (targetrow - leftup > 0 && targetcol - leftup > 0 && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY) {
                whitesleeptwo++;
            }
        }
    }
    else if (rightdown + leftup + 1 == 1) {
        if (targetrow + 2 <= BOARDMAX && targetcol + 2 <= BOARDMAX && board[targetrow + 1][targetcol + 1] == EMPTY && board[targetrow + 2][targetcol + 2] == WHITE) {
            whitesleeptwo++;
        }
        if (targetrow - 2 >= 0 && targetcol - 2 >= 0 && board[targetrow - 1][targetcol - 1] == EMPTY && board[targetrow - 2][targetcol - 2] == WHITE) {
            whitesleeptwo++;
        }
    }
}