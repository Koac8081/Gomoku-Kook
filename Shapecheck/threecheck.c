//检查某处活三，眠三的函数

#include <stdio.h>
#include "../gomoku.h"

int blacklivethree; //黑棋活三
int whitelivethree; //白棋活三
int blacksleepthree; //黑棋眠三
int whitesleepthree; //白棋眠三
int blackjumpthree; //黑棋跳活三
int whitejumpthree; //白棋跳活三

void threecheck(int board[BOARDSIZE][BOARDSIZE], int targetrow, int targetcol) { 
    blacklivethree = 0; 
    whitelivethree = 0;
    blacksleepthree = 0; 
    whitesleepthree = 0; 
    blackjumpthree = 0; // 初始化跳活三计数
    whitejumpthree = 0; // 初始化跳活三计数

    int targets[2] = {BLACK, WHITE};
    for (int i = 0; i < 2; i++) {
        int color = targets[i];
        int *live = (color == BLACK) ? &blacklivethree : &whitelivethree;
        int *sleep = (color == BLACK) ? &blacksleepthree : &whitesleepthree;
        int *jump = (color == BLACK) ? &blackjumpthree : &whitejumpthree; // 跳活三计数

        int dr[] = {1, 0, 1, 1}; // 纵，横，135°-315°，45°-225°
        int dc[] = {0, 1, 1, -1};

        for (int d = 0; d < 4; d++) {
            int r = dr[d], c = dc[d];

            // 统计紧邻的连子数
            int npos = 1;
            while (targetrow + npos * r >= 0 && targetrow + npos * r <= BOARDMAX && targetcol + npos * c >= 0 && targetcol + npos * c <= BOARDMAX && board[targetrow + npos * r][targetcol + npos * c] == color){
                npos++;
            }
            int nneg = 1;
            while (targetrow - nneg * r >= 0 && targetrow - nneg * r <= BOARDMAX &&targetcol - nneg * c >= 0 && targetcol - nneg * c <= BOARDMAX && board[targetrow - nneg * r][targetcol - nneg * c] == color){
                nneg++;
            }
            int continuous = npos + nneg - 1; 
            // 判定连三
            if (continuous == 3) {
                int r1 = targetrow - nneg * r, c1 = targetcol - nneg * c;
                int r2 = targetrow + npos * r, c2 = targetcol + npos * c;
                int s1 = (r1 >= 0 && r1 <= BOARDMAX && c1 >= 0 && c1 <= BOARDMAX && board[r1][c1] == EMPTY);
                int s2 = (r2 >= 0 && r2 <= BOARDMAX && c2 >= 0 && c2 <= BOARDMAX && board[r2][c2] == EMPTY);
                if (s1 && s2) (*live)++; // 连三（活三）
                else if (s1 || s2) (*sleep)++; // 眠三
            }
            // 判定跳三 (只有连子不足3时才检查是否有跳三)
            else if (continuous < 3) {
                int jump_found = 0;
                // 正向探测
                int gr = targetrow + npos * r, gc = targetcol + npos * c;
                if (gr >= 0 && gr <= BOARDMAX && gc >= 0 && gc <= BOARDMAX && board[gr][gc] == EMPTY) {
                    int k = 1;
                    while (gr + k * r >= 0 && gr + k * r <= BOARDMAX && gc + k * c >= 0 && gc + k * c <= BOARDMAX && board[gr + k * r][gc + k * c] == color){
                        k++;
                    }
                    if (continuous + (k - 1) == 3) {
                        int r_h = targetrow - nneg * r, c_h = targetcol - nneg * c;
                        int r_t = gr + k * r, c_t = gc + k * c;
                        int s1 = (r_h >= 0 && r_h <= BOARDMAX && c_h >= 0 && c_h <= BOARDMAX && board[r_h][c_h] == EMPTY);
                        int s2 = (r_t >= 0 && r_t <= BOARDMAX && c_t >= 0 && c_t <= BOARDMAX && board[r_t][c_t] == EMPTY);
                        if (s1 && s2){
                            (*jump)++; // 记录跳活三
                        } 
                        jump_found = 1; 
                    }
                }
                // 反向探测（仅在正向没发现跳三时执行，防止重复）
                if (!jump_found) {
                    int gr_n = targetrow - nneg * r, gc_n = targetcol - nneg * c;
                    if (gr_n >= 0 && gr_n <= BOARDMAX && gc_n >= 0 && gc_n <= BOARDMAX && board[gr_n][gc_n] == EMPTY){
                        int k = 1;
                        while (gr_n - k * r >= 0 && gr_n - k * r <= BOARDMAX && gc_n - k * c >= 0 && gc_n - k * c <= BOARDMAX &&board[gr_n - k * r][gc_n - k * c] == color){
                            k++;
                        }
                        if (continuous + (k - 1) == 3){
                            int r_h = gr_n - k * r, c_h = gc_n - k * c;
                            int r_t = targetrow + npos * r, c_t = targetcol + npos * c;
                            int s1 = (r_h >= 0 && r_h <= BOARDMAX && c_h >= 0 && c_h <= BOARDMAX && board[r_h][c_h] == EMPTY);
                            int s2 = (r_t >= 0 && r_t <= BOARDMAX && c_t >= 0 && c_t <= BOARDMAX && board[r_t][c_t] == EMPTY);
                            if (s1 && s2){
                                (*jump)++; // 记录跳活三
                            }
                        }
                    }
                }
            }
        }
    }
}
