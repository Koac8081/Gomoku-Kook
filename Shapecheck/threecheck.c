//检查某处活三，眠三的函数
#include <stdio.h>
#include "../gomoku.h"

int blacklivethree, whitelivethree, blacksleepthree, whitesleepthree;

void threecheck(int board[BOARDSIZE][BOARDSIZE], int targetrow, int targetcol) {
    blacklivethree = 0; whitelivethree = 0;
    blacksleepthree = 0; whitesleepthree = 0;

    int colors[2] = {BLACK, WHITE};
    for (int i = 0; i < 2; i++) {
        int color = colors[i];
        int *live = (color == BLACK) ? &blacklivethree : &whitelivethree;
        int *sleep = (color == BLACK) ? &blacksleepthree : &whitesleepthree;

        int dr[] = {1, 0, 1, 1}; // 纵、横、135、45
        int dc[] = {0, 1, 1, -1};

        for (int d = 0; d < 4; d++) {
            int r = dr[d], c = dc[d];

            // 统计紧邻的连子（含模拟落子点）
            int n_pos = 1;
            while (targetrow + n_pos * r >= 0 && targetrow + n_pos * r <= BOARDMAX &&
                   targetcol + n_pos * c >= 0 && targetcol + n_pos * c <= BOARDMAX &&
                   board[targetrow + n_pos * r][targetcol + n_pos * c] == color) n_pos++;
            
            int n_neg = 1;
            while (targetrow - n_neg * r >= 0 && targetrow - n_neg * r <= BOARDMAX &&
                   targetcol - n_neg * c >= 0 && targetcol - n_neg * c <= BOARDMAX &&
                   board[targetrow - n_neg * r][targetcol - n_neg * c] == color) n_neg++;

            int continuous = n_pos + n_neg - 1; 

            // --- 判定连三 ---
            if (continuous == 3) {
                int r1 = targetrow - n_neg * r, c1 = targetcol - n_neg * c;
                int r2 = targetrow + n_pos * r, c2 = targetcol + n_pos * c;
                int s1 = (r1 >= 0 && r1 <= BOARDMAX && c1 >= 0 && c1 <= BOARDMAX && board[r1][c1] == EMPTY);
                int s2 = (r2 >= 0 && r2 <= BOARDMAX && c2 >= 0 && c2 <= BOARDMAX && board[r2][c2] == EMPTY);
                if (s1 && s2) (*live)++;
                else if (s1 || s2) (*sleep)++;
            }
            // --- 判定跳三 (只有连子不足3时才查跳) ---
            else if (continuous < 3) {
                int jump_found = 0;
                // 正向探测
                int gr = targetrow + n_pos * r, gc = targetcol + n_pos * c;
                if (gr >= 0 && gr <= BOARDMAX && gc >= 0 && gc <= BOARDMAX && board[gr][gc] == EMPTY) {
                    int k = 1;
                    while (gr + k * r >= 0 && gr + k * r <= BOARDMAX && gc + k * c >= 0 && gc + k * c <= BOARDMAX &&
                           board[gr + k * r][gc + k * c] == color) k++;
                    if (continuous + (k - 1) == 3) {
                        int r_h = targetrow - n_neg * r, c_h = targetcol - n_neg * c;
                        int r_t = gr + k * r, c_t = gc + k * c;
                        int s1 = (r_h >= 0 && r_h <= BOARDMAX && c_h >= 0 && c_h <= BOARDMAX && board[r_h][c_h] == EMPTY);
                        int s2 = (r_t >= 0 && r_t <= BOARDMAX && c_t >= 0 && c_t <= BOARDMAX && board[r_t][c_t] == EMPTY);
                        if (s1 && s2) (*live)++; else if (s1 || s2) (*sleep)++;
                        jump_found = 1; 
                    }
                }
                // 反向探测（仅在正向没发现跳三时执行，防止重复）
                if (!jump_found) {
                    int gr_n = targetrow - n_neg * r, gc_n = targetcol - n_neg * c;
                    if (gr_n >= 0 && gr_n <= BOARDMAX && gc_n >= 0 && gc_n <= BOARDMAX && board[gr_n][gc_n] == EMPTY) {
                        int k = 1;
                        while (gr_n - k * r >= 0 && gr_n - k * r <= BOARDMAX && gc_n - k * c >= 0 && gc_n - k * c <= BOARDMAX &&
                               board[gr_n - k * r][gc_n - k * c] == color) k++;
                        if (continuous + (k - 1) == 3) {
                            int r_h = gr_n - k * r, c_h = gc_n - k * c;
                            int r_t = targetrow + n_pos * r, c_t = targetcol + n_pos * c;
                            int s1 = (r_h >= 0 && r_h <= BOARDMAX && c_h >= 0 && c_h <= BOARDMAX && board[r_h][c_h] == EMPTY);
                            int s2 = (r_t >= 0 && r_t <= BOARDMAX && c_t >= 0 && c_t <= BOARDMAX && board[r_t][c_t] == EMPTY);
                            if (s1 && s2) (*live)++; else if (s1 || s2) (*sleep)++;
                        }
                    }
                }
            }
        }
    }
}