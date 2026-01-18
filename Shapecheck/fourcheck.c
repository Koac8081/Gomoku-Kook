//检查下在此处是否能形成活四,冲四

#include <stdio.h>
#include "../gomoku.h"

int blacklivefour = 0; //黑棋活四数
int whitelivefour = 0; //白棋活四数

int blackchargefour = 0; //黑棋冲四数
int whitechargefour = 0; //白棋冲四数

int blackjumpfour = 0; //黑棋跳四数
int whitejumpfour = 0; //白棋跳四数

void fourcheck(int board[BOARDSIZE][BOARDSIZE], int targetrow, int targetcol) {
    blacklivefour = 0;
    whitelivefour = 0;
    blackjumpfour = 0;
    whitejumpfour = 0;
    blackchargefour = 0;
    whitechargefour = 0; //重置

    // 黑棋检索
    // 纵向检索
    int colnum_up = 0; //向上连子数
    while (1) {
        if (targetrow - colnum_up - 1 >= 0 && board[targetrow - colnum_up - 1][targetcol] == BLACK) {
            colnum_up++;
        }
        else {
            break;
        }
    }
    int colnum_down = 0; //向下连子数
    while (1) {
        if (targetrow + colnum_down + 1 <= BOARDMAX && board[targetrow + colnum_down + 1][targetcol] == BLACK) {
            colnum_down++;
        }
        else {
            break;
        }
    }

    if (colnum_down + colnum_up + 1 == 4) {
        // 活四
        if (targetrow - colnum_up > 0 && targetrow + colnum_down < BOARDMAX &&
            board[targetrow + colnum_down + 1][targetcol] == EMPTY &&
            board[targetrow - colnum_up - 1][targetcol] == EMPTY) {
            blacklivefour++;
        }
        else {
            // 冲四，一端被白棋堵
            if (targetrow + colnum_down < BOARDMAX && targetrow - colnum_up > 0) {
                if (board[targetrow + colnum_down + 1][targetcol] == EMPTY && board[targetrow - colnum_up - 1][targetcol] == WHITE)
                    blackchargefour++;
                else if (board[targetrow + colnum_down + 1][targetcol] == WHITE && board[targetrow - colnum_up - 1][targetcol] == EMPTY)
                    blackchargefour++;
            }
            // 冲四，一端是边界
            if (targetrow + colnum_down == BOARDMAX && targetrow - colnum_up > 0 && board[targetrow - colnum_up - 1][targetcol] == EMPTY) {
                blackchargefour++;
            }
            else if (targetrow - colnum_up == 0 && targetrow + colnum_down < BOARDMAX && board[targetrow + colnum_down + 1][targetcol] == EMPTY) {
                blackchargefour++;
            }
        }
    }
    else {
        // 写完之后，发现还有跳四这种情况，即“黑黑空黑黑”或“黑空黑黑黑”，视作冲四 
        if (colnum_up + colnum_down + 1 == 1) {
            if (targetrow + 4 <= BOARDMAX && board[targetrow + 1][targetcol] == EMPTY && board[targetrow + 2][targetcol] == BLACK && board[targetrow + 3][targetcol] == BLACK && board[targetrow + 4][targetcol] == BLACK) {
                blackjumpfour++;
            }
            if (targetrow - 4 >= 0 && board[targetrow - 1][targetcol] == EMPTY && board[targetrow - 2][targetcol] == BLACK && board[targetrow - 3][targetcol] == BLACK && board[targetrow - 4][targetcol] == BLACK) {
                blackjumpfour++;
            }
        }
        else if (colnum_up + colnum_down + 1 == 2) {
            int top = targetrow - colnum_up;
            int bottom = targetrow + colnum_down;
            if (bottom + 3 <= BOARDMAX && board[bottom + 1][targetcol] == EMPTY && board[bottom + 2][targetcol] == BLACK && board[bottom + 3][targetcol] == BLACK) {
                blackjumpfour++;
            }
            if (top - 3 >= 0 && board[top - 1][targetcol] == EMPTY && board[top - 2][targetcol] == BLACK && board[top - 3][targetcol] == BLACK) {
                blackjumpfour++;
            }
        }
        else if (colnum_up + colnum_down + 1 == 3) {
            int top = targetrow - colnum_up;
            int bottom = targetrow + colnum_down;
            if (bottom + 2 <= BOARDMAX && board[bottom + 1][targetcol] == EMPTY && board[bottom + 2][targetcol] == BLACK) {
                blackjumpfour++;
            }
            if (top - 2 >= 0 && board[top - 1][targetcol] == EMPTY && board[top - 2][targetcol] == BLACK) {
                blackjumpfour++;
            }
        }
    }

    // 横向检索
    int rownum_left = 0; //向左连子数
    while (1) {
        if (targetcol - rownum_left - 1 >= 0 && board[targetrow][targetcol - rownum_left - 1] == BLACK) {
            rownum_left++;
        }
        else {
            break;
        }
    }
    int rownum_right = 0; //向右连子数
    while (1) {
        if (targetcol + rownum_right + 1 <= BOARDMAX && board[targetrow][targetcol + rownum_right + 1] == BLACK) {
            rownum_right++;
        }
        else {
            break;
        }
    }

    if (rownum_left + rownum_right + 1 == 4) {
        // 活四
        if (targetcol - rownum_left > 0 && targetcol + rownum_right < BOARDMAX &&
            board[targetrow][targetcol - rownum_left - 1] == EMPTY &&
            board[targetrow][targetcol + rownum_right + 1] == EMPTY) {
            blacklivefour++;
        }
        else {
            // 冲四，一端被白棋堵
            if (targetcol - rownum_left > 0 && targetcol + rownum_right < BOARDMAX) {
                if (board[targetrow][targetcol - rownum_left - 1] == WHITE && board[targetrow][targetcol + rownum_right + 1] == EMPTY)
                    blackchargefour++;
                else if (board[targetrow][targetcol - rownum_left - 1] == EMPTY && board[targetrow][targetcol + rownum_right + 1] == WHITE)
                    blackchargefour++;
            }
            // 冲四，一端是边界
            if (targetcol + rownum_right == BOARDMAX && targetcol - rownum_left > 0 && board[targetrow][targetcol - rownum_left - 1] == EMPTY) {
                blackchargefour++;
            }
            else if (targetcol - rownum_left == 0 && targetcol + rownum_right < BOARDMAX && board[targetrow][targetcol + rownum_right + 1] == EMPTY) {
                blackchargefour++;
            }
        }
    }
    else {
        // 跳四 
        if (rownum_left + rownum_right + 1 == 1) {
            if (targetcol + 4 <= BOARDMAX && board[targetrow][targetcol + 1] == EMPTY && board[targetrow][targetcol + 2] == BLACK && board[targetrow][targetcol + 3] == BLACK && board[targetrow][targetcol + 4] == BLACK) {
                blackjumpfour++;
            }
            if (targetcol - 4 >= 0 && board[targetrow][targetcol - 1] == EMPTY && board[targetrow][targetcol - 2] == BLACK && board[targetrow][targetcol - 3] == BLACK && board[targetrow][targetcol - 4] == BLACK) {
                blackjumpfour++;
            }
        }
        else if (rownum_left + rownum_right + 1 == 2) {
            int left = targetcol - rownum_left;
            int right = targetcol + rownum_right;
            if (right + 3 <= BOARDMAX && board[targetrow][right + 1] == EMPTY && board[targetrow][right + 2] == BLACK && board[targetrow][right + 3] == BLACK) {
                blackjumpfour++;
            }
            if (left - 3 >= 0 && board[targetrow][left - 1] == EMPTY && board[targetrow][left - 2] == BLACK && board[targetrow][left - 3] == BLACK) {
                blackjumpfour++;
            }
        }
        else if (rownum_left + rownum_right + 1 == 3) {
            int left = targetcol - rownum_left;
            int right = targetcol + rownum_right;
            if (right + 2 <= BOARDMAX && board[targetrow][right + 1] == EMPTY && board[targetrow][right + 2] == BLACK) {
                blackjumpfour++;
            }
            if (left - 2 >= 0 && board[targetrow][left - 1] == EMPTY && board[targetrow][left - 2] == BLACK) {
                blackjumpfour++;
            }
        }
    }

    // 45°-225° 方向检索 (右上-左下)
    int rightup = 0; //右上连子数
    while (1) {
        if (targetrow - rightup - 1 >= 0 && targetcol + rightup + 1 <= BOARDMAX && board[targetrow - rightup - 1][targetcol + rightup + 1] == BLACK) {
            rightup++;
        }
        else {
            break;
        }
    }
    int leftdown = 0; //左下连子数
    while (1) {
        if (targetrow + leftdown + 1 <= BOARDMAX && targetcol - leftdown - 1 >= 0 && board[targetrow + leftdown + 1][targetcol - leftdown - 1] == BLACK) {
            leftdown++;
        }
        else {
            break;
        }
    }

    if (rightup + leftdown + 1 == 4) {
        // 活四
        if (targetrow + leftdown < BOARDMAX && targetcol - leftdown > 0 &&
            targetrow - rightup > 0 && targetcol + rightup < BOARDMAX &&
            board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY &&
            board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY) {
            blacklivefour++;
        }
        else {
            // 冲四，一端被堵
            if (targetrow + leftdown < BOARDMAX && targetcol - leftdown > 0 && targetrow - rightup > 0 && targetcol + rightup < BOARDMAX) {
                if (board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY && board[targetrow - rightup - 1][targetcol + rightup + 1] == WHITE) {
                    blackchargefour++;
                }
                else if (board[targetrow + leftdown + 1][targetcol - leftdown - 1] == WHITE && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY) {
                    blackchargefour++;
                }
            }
            // 冲四，边界检查 
            if ((targetrow - rightup == 0 || targetcol + rightup == BOARDMAX) && targetrow + leftdown < BOARDMAX && targetcol - leftdown > 0) {
                if (board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY) {
                    blackchargefour++;
                }
            }
            else if ((targetrow + leftdown == BOARDMAX || targetcol - leftdown == 0) && targetrow - rightup > 0 && targetcol + rightup < BOARDMAX) {
                if (board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY) {
                    blackchargefour++;
                }
            }
        }
    }
    else {
        // 跳四 
        int total = rightup + leftdown + 1;
        if (total == 1) {
            if (targetrow + 4 <= BOARDMAX && targetcol - 4 >= 0 && board[targetrow + 1][targetcol - 1] == EMPTY && board[targetrow + 2][targetcol - 2] == BLACK && board[targetrow + 3][targetcol - 3] == BLACK && board[targetrow + 4][targetcol - 4] == BLACK) {
                blackjumpfour++;
            }
            if (targetrow - 4 >= 0 && targetcol + 4 <= BOARDMAX && board[targetrow - 1][targetcol + 1] == EMPTY && board[targetrow - 2][targetcol + 2] == BLACK && board[targetrow - 3][targetcol + 3] == BLACK && board[targetrow - 4][targetcol + 4] == BLACK) {
                blackjumpfour++;
            }
        }
        else if (total == 2) {
            int hr = targetrow - rightup, hc = targetcol + rightup;
            int tr = targetrow + leftdown, tc = targetcol - leftdown;
            if (tr + 3 <= BOARDMAX && tc - 3 >= 0 && board[tr + 1][tc - 1] == EMPTY && board[tr + 2][tc - 2] == BLACK && board[tr + 3][tc - 3] == BLACK) {
                blackjumpfour++;
            }
            if (hr - 3 >= 0 && hc + 3 <= BOARDMAX && board[hr - 1][hc + 1] == EMPTY && board[hr - 2][hc + 2] == BLACK && board[hr - 3][hc + 3] == BLACK) {
                blackjumpfour++;
            }
        }
        else if (total == 3) {
            int hr = targetrow - rightup, hc = targetcol + rightup;
            int tr = targetrow + leftdown, tc = targetcol - leftdown;
            if (tr + 2 <= BOARDMAX && tc - 2 >= 0 && board[tr + 1][tc - 1] == EMPTY && board[tr + 2][tc - 2] == BLACK) {
                blackjumpfour++;
            }
            if (hr - 2 >= 0 && hc + 2 <= BOARDMAX && board[hr - 1][hc + 1] == EMPTY && board[hr - 2][hc + 2] == BLACK) {
                blackjumpfour++;
            }
        }
    }

    // 135°-315° 方向检索 (左上-右下)
    int rightdown = 0; //右下连子数
    while (1) {
        if (targetrow + rightdown + 1 <= BOARDMAX && targetcol + rightdown + 1 <= BOARDMAX && board[targetrow + rightdown + 1][targetcol + rightdown + 1] == BLACK) {
            rightdown++;
        }
        else {
            break;
        }
    }
    int leftup = 0; //左上连子数
    while (1) {
        if (targetrow - leftup - 1 >= 0 && targetcol - leftup - 1 >= 0 && board[targetrow - leftup - 1][targetcol - leftup - 1] == BLACK) {
            leftup++;
        }
        else {
            break;
        }
    }

    if (rightdown + leftup + 1 == 4) {
        // 活四
        if (targetrow + rightdown < BOARDMAX && targetcol + rightdown < BOARDMAX &&
            targetrow - leftup > 0 && targetcol - leftup > 0 &&
            board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY &&
            board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY) {
            blacklivefour++;
        }
        else {
            // 冲四，一端被堵
            if (targetrow + rightdown < BOARDMAX && targetcol + rightdown < BOARDMAX && targetrow - leftup > 0 && targetcol - leftup > 0) {
                if (board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY && board[targetrow - leftup - 1][targetcol - leftup - 1] == WHITE) {
                    blackchargefour++;
                }
                else if (board[targetrow + rightdown + 1][targetcol + rightdown + 1] == WHITE && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY) {
                    blackchargefour++;
                }
            }
            // 冲四，边界检查 
            if ((targetcol + rightdown == BOARDMAX || targetrow + rightdown == BOARDMAX) && targetrow - leftup > 0 && targetcol - leftup > 0) {
                if (board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY) {
                    blackchargefour++;
                }
            }
            else if ((targetcol - leftup == 0 || targetrow - leftup == 0) && targetrow + rightdown < BOARDMAX && targetcol + rightdown < BOARDMAX) {
                if (board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY) {
                    blackchargefour++;
                }
            }
        }
    }
    else {
        // 跳四 
        int total = rightdown + leftup + 1;
        if (total == 1) {
            if (targetrow + 4 <= BOARDMAX && targetcol + 4 <= BOARDMAX && board[targetrow + 1][targetcol + 1] == EMPTY && board[targetrow + 2][targetcol + 2] == BLACK && board[targetrow + 3][targetcol + 3] == BLACK && board[targetrow + 4][targetcol + 4] == BLACK) {
                blackjumpfour++;
            }
            if (targetrow - 4 >= 0 && targetcol - 4 >= 0 && board[targetrow - 1][targetcol - 1] == EMPTY && board[targetrow - 2][targetcol - 2] == BLACK && board[targetrow - 3][targetcol - 3] == BLACK && board[targetrow - 4][targetcol - 4] == BLACK) {
                blackjumpfour++;
            }
        }
        else if (total == 2) {
            int hr = targetrow - leftup, hc = targetcol - leftup;
            int tr = targetrow + rightdown, tc = targetcol + rightdown;
            if (tr + 3 <= BOARDMAX && tc + 3 <= BOARDMAX && board[tr + 1][tc + 1] == EMPTY && board[tr + 2][tc + 2] == BLACK && board[tr + 3][tc + 3] == BLACK) {
                blackjumpfour++;
            }
            if (hr - 3 >= 0 && hc - 3 >= 0 && board[hr - 1][hc - 1] == EMPTY && board[hr - 2][hc - 2] == BLACK && board[hr - 3][hc - 3] == BLACK) {
                blackjumpfour++;
            }
        }
        else if (total == 3) {
            int hr = targetrow - leftup, hc = targetcol - leftup;
            int tr = targetrow + rightdown, tc = targetcol + rightdown;
            if (tr + 2 <= BOARDMAX && tc + 2 <= BOARDMAX && board[tr + 1][tc + 1] == EMPTY && board[tr + 2][tc + 2] == BLACK) {
                blackjumpfour++;
            }
            if (hr - 2 >= 0 && hc - 2 >= 0 && board[hr - 1][hc - 1] == EMPTY && board[hr - 2][hc - 2] == BLACK) {
                blackjumpfour++;
            }
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

    if (colnum_down + colnum_up + 1 == 4) {
        if (targetrow - colnum_up > 0 && targetrow + colnum_down < BOARDMAX &&
            board[targetrow + colnum_down + 1][targetcol] == EMPTY &&
            board[targetrow - colnum_up - 1][targetcol] == EMPTY) {
            whitelivefour++;
        }
        else {
            if (targetrow + colnum_down < BOARDMAX && targetrow - colnum_up > 0) {
                if (board[targetrow + colnum_down + 1][targetcol] == EMPTY && board[targetrow - colnum_up - 1][targetcol] == BLACK)
                    whitechargefour++;
                else if (board[targetrow + colnum_down + 1][targetcol] == BLACK && board[targetrow - colnum_up - 1][targetcol] == EMPTY)
                    whitechargefour++;
            }
            if (targetrow + colnum_down == BOARDMAX && targetrow - colnum_up > 0 && board[targetrow - colnum_up - 1][targetcol] == EMPTY) {
                whitechargefour++;
            }
            else if (targetrow - colnum_up == 0 && targetrow + colnum_down < BOARDMAX && board[targetrow + colnum_down + 1][targetcol] == EMPTY) {
                whitechargefour++;
            }
        }
    }
    else {
        // 跳四
        if (colnum_up + colnum_down + 1 == 1) {
            if (targetrow + 4 <= BOARDMAX && board[targetrow + 1][targetcol] == EMPTY && board[targetrow + 2][targetcol] == WHITE && board[targetrow + 3][targetcol] == WHITE && board[targetrow + 4][targetcol] == WHITE) {
                whitejumpfour++;
            }
            if (targetrow - 4 >= 0 && board[targetrow - 1][targetcol] == EMPTY && board[targetrow - 2][targetcol] == WHITE && board[targetrow - 3][targetcol] == WHITE && board[targetrow - 4][targetcol] == WHITE) {
                whitejumpfour++;
            }
        }
        else if (colnum_up + colnum_down + 1 == 2) {
            int top = targetrow - colnum_up;
            int bottom = targetrow + colnum_down;
            if (bottom + 3 <= BOARDMAX && board[bottom + 1][targetcol] == EMPTY && board[bottom + 2][targetcol] == WHITE && board[bottom + 3][targetcol] == WHITE) {
                whitejumpfour++;
            }
            if (top - 3 >= 0 && board[top - 1][targetcol] == EMPTY && board[top - 2][targetcol] == WHITE && board[top - 3][targetcol] == WHITE) {
                whitejumpfour++;
            }
        }
        else if (colnum_up + colnum_down + 1 == 3) {
            int top = targetrow - colnum_up;
            int bottom = targetrow + colnum_down;
            if (bottom + 2 <= BOARDMAX && board[bottom + 1][targetcol] == EMPTY && board[bottom + 2][targetcol] == WHITE) {
                whitejumpfour++;
            }
            if (top - 2 >= 0 && board[top - 1][targetcol] == EMPTY && board[top - 2][targetcol] == WHITE) {
                whitejumpfour++;
            }
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

    if (rownum_left + rownum_right + 1 == 4) {
        if (targetcol - rownum_left > 0 && targetcol + rownum_right < BOARDMAX &&
            board[targetrow][targetcol - rownum_left - 1] == EMPTY &&
            board[targetrow][targetcol + rownum_right + 1] == EMPTY) {
            whitelivefour++;
        }
        else {
            if (targetcol - rownum_left > 0 && targetcol + rownum_right < BOARDMAX) {
                if (board[targetrow][targetcol - rownum_left - 1] == BLACK && board[targetrow][targetcol + rownum_right + 1] == EMPTY)
                    whitechargefour++;
                else if (board[targetrow][targetcol - rownum_left - 1] == EMPTY && board[targetrow][targetcol + rownum_right + 1] == BLACK)
                    whitechargefour++;
            }
            if (targetcol + rownum_right == BOARDMAX && targetcol - rownum_left > 0 && board[targetrow][targetcol - rownum_left - 1] == EMPTY) {
                whitechargefour++;
            }
            else if (targetcol - rownum_left == 0 && targetcol + rownum_right < BOARDMAX && board[targetrow][targetcol + rownum_right + 1] == EMPTY) {
                whitechargefour++;
            }
        }
    }
    else {
        // 跳四
        if (rownum_left + rownum_right + 1 == 1) {
            if (targetcol + 4 <= BOARDMAX && board[targetrow][targetcol + 1] == EMPTY && board[targetrow][targetcol + 2] == WHITE && board[targetrow][targetcol + 3] == WHITE && board[targetrow][targetcol + 4] == WHITE) {
                whitejumpfour++;
            }
            if (targetcol - 4 >= 0 && board[targetrow][targetcol - 1] == EMPTY && board[targetrow][targetcol - 2] == WHITE && board[targetrow][targetcol - 3] == WHITE && board[targetrow][targetcol - 4] == WHITE) {
                whitejumpfour++;
            }
        }
        else if (rownum_left + rownum_right + 1 == 2) {
            int left = targetcol - rownum_left;
            int right = targetcol + rownum_right;
            if (right + 3 <= BOARDMAX && board[targetrow][right + 1] == EMPTY && board[targetrow][right + 2] == WHITE && board[targetrow][right + 3] == WHITE) {
                whitejumpfour++;
            }
            if (left - 3 >= 0 && board[targetrow][left - 1] == EMPTY && board[targetrow][left - 2] == WHITE && board[targetrow][left - 3] == WHITE) {
                whitejumpfour++;
            }
        }
        else if (rownum_left + rownum_right + 1 == 3) {
            int left = targetcol - rownum_left;
            int right = targetcol + rownum_right;
            if (right + 2 <= BOARDMAX && board[targetrow][right + 1] == EMPTY && board[targetrow][right + 2] == WHITE) {
                whitejumpfour++;
            }
            if (left - 2 >= 0 && board[targetrow][left - 1] == EMPTY && board[targetrow][left - 2] == WHITE) {
                whitejumpfour++;
            }
        }
    }

    // 45°-225° 方向检索 (右上-左下)
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

    if (rightup + leftdown + 1 == 4) {
        if (targetrow + leftdown < BOARDMAX && targetcol - leftdown > 0 &&
            targetrow - rightup > 0 && targetcol + rightup < BOARDMAX &&
            board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY &&
            board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY) {
            whitelivefour++;
        }
        else {
            if (targetrow + leftdown < BOARDMAX && targetcol - leftdown > 0 && targetrow - rightup > 0 && targetcol + rightup < BOARDMAX) {
                if (board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY && board[targetrow - rightup - 1][targetcol + rightup + 1] == BLACK) {
                    whitechargefour++;
                }
                else if (board[targetrow + leftdown + 1][targetcol - leftdown - 1] == BLACK && board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY) {
                    whitechargefour++;
                }
            }
            if ((targetcol + rightup == BOARDMAX || targetrow - rightup == 0) && targetrow + leftdown < BOARDMAX && targetcol - leftdown > 0) {
                if (board[targetrow + leftdown + 1][targetcol - leftdown - 1] == EMPTY) {
                    whitechargefour++;
                }
            }
            else if ((targetcol - leftdown == 0 || targetrow + leftdown == BOARDMAX) && targetrow - rightup > 0 && targetcol + rightup < BOARDMAX) {
                if (board[targetrow - rightup - 1][targetcol + rightup + 1] == EMPTY) {
                    whitechargefour++;
                }
            }
        }
    }
    else {
        // 跳四
        int total = rightup + leftdown + 1;
        if (total == 1) {
            if (targetrow + 4 <= BOARDMAX && targetcol - 4 >= 0 && board[targetrow + 1][targetcol - 1] == EMPTY && board[targetrow + 2][targetcol - 2] == WHITE && board[targetrow + 3][targetcol - 3] == WHITE && board[targetrow + 4][targetcol - 4] == WHITE) {
                whitejumpfour++;
            }
            if (targetrow - 4 >= 0 && targetcol + 4 <= BOARDMAX && board[targetrow - 1][targetcol + 1] == EMPTY && board[targetrow - 2][targetcol + 2] == WHITE && board[targetrow - 3][targetcol + 3] == WHITE && board[targetrow - 4][targetcol + 4] == WHITE) {
                whitejumpfour++;
            }
        }
        else if (total == 2) {
            int hr = targetrow - rightup, hc = targetcol + rightup;
            int tr = targetrow + leftdown, tc = targetcol - leftdown;
            if (tr + 3 <= BOARDMAX && tc - 3 >= 0 && board[tr + 1][tc - 1] == EMPTY && board[tr + 2][tc - 2] == WHITE && board[tr + 3][tc - 3] == WHITE) {
                whitejumpfour++;
            }
            if (hr - 3 >= 0 && hc + 3 <= BOARDMAX && board[hr - 1][hc + 1] == EMPTY && board[hr - 2][hc + 2] == WHITE && board[hr - 3][hc + 3] == WHITE) {
                whitejumpfour++;
            }
        }
        else if (total == 3) {
            int hr = targetrow - rightup, hc = targetcol + rightup;
            int tr = targetrow + leftdown, tc = targetcol - leftdown;
            if (tr + 2 <= BOARDMAX && tc - 2 >= 0 && board[tr + 1][tc - 1] == EMPTY && board[tr + 2][tc - 2] == WHITE) {
                whitejumpfour++;
            }
            if (hr - 2 >= 0 && hc + 2 <= BOARDMAX && board[hr - 1][hc + 1] == EMPTY && board[hr - 2][hc + 2] == WHITE) {
                whitejumpfour++;
            }
        }
    }

    //135°-315° 方向检索 (左上-右下)
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

    if (rightdown + leftup + 1 == 4) {
        if (targetrow + rightdown < BOARDMAX && targetcol + rightdown < BOARDMAX &&
            targetrow - leftup > 0 && targetcol - leftup > 0 &&
            board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY &&
            board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY) {
            whitelivefour++;
        }
        else {
            if (targetrow + rightdown < BOARDMAX && targetcol + rightdown < BOARDMAX && targetrow - leftup > 0 && targetcol - leftup > 0) {
                if (board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY && board[targetrow - leftup - 1][targetcol - leftup - 1] == BLACK) {
                    whitechargefour++;
                }
                else if (board[targetrow + rightdown + 1][targetcol + rightdown + 1] == BLACK && board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY) {
                    whitechargefour++;
                }
            }
            if ((targetcol + rightdown == BOARDMAX || targetrow + rightdown == BOARDMAX) && targetrow - leftup > 0 && targetcol - leftup > 0) {
                if (board[targetrow - leftup - 1][targetcol - leftup - 1] == EMPTY) {
                    whitechargefour++;
                }
            }
            else if ((targetcol - leftup == 0 || targetrow - leftup == 0) && targetrow + rightdown < BOARDMAX && targetcol + rightdown < BOARDMAX) {
                if (board[targetrow + rightdown + 1][targetcol + rightdown + 1] == EMPTY) {
                    whitechargefour++;
                }
            }
        }
    }
    else {
        // 跳四
        int total = rightdown + leftup + 1;
        if (total == 1) {
            if (targetrow + 4 <= BOARDMAX && targetcol + 4 <= BOARDMAX && board[targetrow + 1][targetcol + 1] == EMPTY && board[targetrow + 2][targetcol + 2] == WHITE && board[targetrow + 3][targetcol + 3] == WHITE && board[targetrow + 4][targetcol + 4] == WHITE) {
                whitejumpfour++;
            }
            if (targetrow - 4 >= 0 && targetcol - 4 >= 0 && board[targetrow - 1][targetcol - 1] == EMPTY && board[targetrow - 2][targetcol - 2] == WHITE && board[targetrow - 3][targetcol - 3] == WHITE && board[targetrow - 4][targetcol - 4] == WHITE) {
                whitejumpfour++;
            }
        }
        else if (total == 2) {
            int hr = targetrow - leftup, hc = targetcol - leftup;
            int tr = targetrow + rightdown, tc = targetcol + rightdown;
            if (tr + 3 <= BOARDMAX && tc + 3 <= BOARDMAX && board[tr + 1][tc + 1] == EMPTY && board[tr + 2][tc + 2] == WHITE && board[tr + 3][tc + 3] == WHITE) {
                whitejumpfour++;
            }
            if (hr - 3 >= 0 && hc - 3 >= 0 && board[hr - 1][hc - 1] == EMPTY && board[hr - 2][hc - 2] == WHITE && board[hr - 3][hc - 3] == WHITE) {
                whitejumpfour++;
            }
        }
        else if (total == 3) {
            int hr = targetrow - leftup, hc = targetcol - leftup;
            int tr = targetrow + rightdown, tc = targetcol + rightdown;
            if (tr + 2 <= BOARDMAX && tc + 2 <= BOARDMAX && board[tr + 1][tc + 1] == EMPTY && board[tr + 2][tc + 2] == WHITE) {
                whitejumpfour++;
            }
            if (hr - 2 >= 0 && hc - 2 >= 0 && board[hr - 1][hc - 1] == EMPTY && board[hr - 2][hc - 2] == WHITE) {
                whitejumpfour++;
            }
        }
    }
}