//选择不同模式后的游戏进行

#include"../gomoku.h"

void pvemode(){//pve模式
    screenclean();
            printf("您选择了PVE模式\n");
            printf("请选择您要成为黑方或白方:输入“1”使用黑棋进行游戏,输入“2”使用白棋进行游戏\n");
            while(1){//PVE黑白棋选择
                if(scanf("%d",&playerchose) == 1){//输入检测及合法性检查
                    if(playerchose == PLAYERCHOSEBLACK){
                        screenclean();
                        printf("您选择了黑方\n");
                        break;
                    }
                    else if(playerchose == PLAYERCHOSEWHITE){
                        screenclean();
                        printf("您选择了白方\n");
                        break;
                    }
                    else{
                        screenclean();
                        printf("您输入了“1”或“2”以外的其他数字,请重新输入!\n");
                        continue;
                    }
                }
                else{
                    screenclean();
                    printf("输入格式错误,请重新输入!\n");
                    while(getchar() != '\n');
                }
            }
            printf("棋局开始\n");
            emptyboardprint(board);
            if(playerchose == PLAYERCHOSEBLACK){//玩家选择黑棋后的PVE游戏
                aimode = WHITE;
            while(gamestate == UNDERWAY){
                    printf("请玩家落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
                    printf("当前黑棋（玩家）已落%d子,白棋（电脑）已落%d子\n",blackstep,whitestep);
                    while(1){//玩家（黑棋）落子
                goinger = BLACKGO;
                if(scanf("%d %c",&row,&col) == 2){//输入检测及合法性检查
                    if(1 <= row && row <= BOARDSIZE && 1 <= col - 'A' + 1 && col - 'A' + 1 <= BOARDSIZE && board[BOARDSIZE - row][col - 'A'] == EMPTY){
                        board[BOARDSIZE - row][col - 'A'] = BLACK;
                        break;
                    }
                    else{
                        printf("您选择的位置在不在棋盘范围或已经落子,请重新选择!\n");
                        continue;
                    }
                }
                else{
                    printf("输入格式有误,请重新输入!\n");
                    while(getchar() != '\n');
                }
            }
            screenclean();
            boardprint(board,row,col);
            printf("AI决策中...\n");
            blackstep++;
            for(int i = 0;i < BOARDSIZE;i++){//下面提到的对比，检查黑棋下的这一手是不是禁手
                for(int j = 0;j <BOARDSIZE;j++){
                    if(tempban[i][j] == BAN && board[i][j] == BLACK){
                        gamestate = WHITEWIN;
                    }
                }
            }
            wincheck(board,goinger,row,col,blackstep,whitestep);//胜利检查
            if(gamestate == BLACKWIN){
                printf("玩家胜利！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            else if(gamestate == PEACE){
                printf("平局！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            else if(gamestate == WHITEWIN){
                printf("玩家下出禁手，AI胜利！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            goinger = WHITE;
            if(whitestep == 0 && board[6][6] == EMPTY){
                    row = 9;
                    col = 'G';
                    board[6][6] = WHITE; 
                } //限制第一手
            else{
                    Move aiaction = aimove();
                    row = BOARDSIZE - aiaction.x;
                    col = aiaction.y + 'A';
                }
            screenclean();
            boardprint(board,row,col);
            whitestep ++;
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == WHITEWIN){
                printf("AI胜利！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            else if(gamestate == PEACE){
                printf("平局！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            bancheck(tempban,board);//由于棋型检查只能检查棋盘空位，导致相关的函数也都只能检查棋盘空位；这里在白棋下完一手后检查哪里是禁手，再在黑棋下完一手后对比
        }
    }
            else{//玩家选择白棋后的PVE游戏
                aimode = BLACK;
                while(gamestate == UNDERWAY){
                goinger = BLACK;
                if(blackstep == 0){
                    row = 8;
                    col = 'H';
                    board[7][7] = BLACK; 
                } //第一手落正中心
                else if(blackstep == 1){
                    if(board[6][6] == EMPTY){
                        row = 9;
                        col = 'G';
                        board[6][6] = BLACK;
                    }
                    else{
                        row = 7;
                        col = 'I';
                        board[8][8] = BLACK;
                    }
                } //第二手
                else{
                    Move aiaction = aimove();
                    row = BOARDSIZE - aiaction.x;
                    col = aiaction.y + 'A';
                }
                 screenclean();
                 boardprint(board,row,col);
                 blackstep ++;
                 wincheck(board,goinger,row,col,blackstep,whitestep);
                 if(gamestate == BLACKWIN){
                    printf("AI胜利！\n即将重新开始游戏\n");
                    wait(10000);
                    return;
                 }
                 else if(gamestate == PEACE){
                    printf("平局！\n即将重新开始游戏\n");
                    wait(10000);
                    return;
                 }
                    printf("请玩家落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
                    printf("当前黑棋（电脑）已落%d子,白棋（玩家）已落%d子\n",blackstep,whitestep);
                    while(1){//玩家（白棋）落子
                goinger = WHITEGO;
                if(scanf("%d %c",&row,&col) == 2){
                    if(1 <= row && row <= BOARDSIZE && 1 <= col - 'A' + 1 && col - 'A' + 1 <= BOARDSIZE && board[BOARDSIZE - row][col - 'A'] == EMPTY){
                        board[BOARDSIZE - row][col - 'A'] = WHITE;
                        break;
                    }
                    else{
                        printf("您选择的位置在不在棋盘范围或已经落子,请重新选择!\n");
                        continue;
                    }
                }
                else{
                    printf("输入格式有误,请重新输入!\n");
                    while(getchar() != '\n');
                }
            }
            screenclean();
            boardprint(board,row,col);
            printf("AI决策中...\n");
            whitestep++;
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == WHITEWIN){
                printf("玩家胜利！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            else if(gamestate == PEACE){
                printf("平局！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
        }
            }
}

void pvpmode(){//pvp模式
    screenclean();
            printf("您选择了PVP模式\n");
            printf("棋局开始\n");
            emptyboardprint(board);
            while(gamestate == UNDERWAY){
            printf("请黑方落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
            printf("当前黑棋已落%d子,白棋已落%d子\n",blackstep,whitestep);
            while(1){//黑方落子
                goinger = BLACKGO;
                if(scanf("%d %c",&row,&col) == 2){
                    if(1 <= row && row <= BOARDSIZE && 1 <= col - 'A' + 1 && col - 'A' + 1 <= BOARDSIZE && board[BOARDSIZE - row][col - 'A'] == EMPTY){
                        board[BOARDSIZE - row][col - 'A'] = BLACK;
                        break;
                    }
                    else{
                        printf("您选择的位置在不在棋盘范围或已经落子,请重新选择!\n");
                        continue;
                    }
                }
                else{
                    printf("输入格式有误,请重新输入!\n");
                    while(getchar() != '\n');
                }
            }
            screenclean();
            boardprint(board,row,col);
            blackstep++;
            for(int i = 0;i < BOARDSIZE;i++){
                for(int j = 0;j <BOARDSIZE;j++){
                    if(tempban[i][j] == BAN && board[i][j] == BLACK){
                        gamestate = WHITEWIN;
                    }
                }
            }
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == BLACKWIN){
                printf("黑方胜利！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            else if(gamestate == WHITEWIN){
                printf("黑方下出禁手，白方胜利！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            else if(gamestate == PEACE){
                printf("平局！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            printf("请白方落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
            printf("当前黑棋已落%d子,白棋已落%d子\n",blackstep,whitestep);
            while(1){//白方落子
                goinger = WHITEGO;
                if(scanf("%d %c",&row,&col) == 2){
                    if(1 <= row && row <= BOARDSIZE && 1 <= col - 'A' + 1 && col - 'A' + 1 <= BOARDSIZE && board[BOARDSIZE - row][col - 'A'] == EMPTY){
                        board[BOARDSIZE - row][col - 'A'] = WHITE;
                        break;
                    }
                    else{
                        printf("您选择的位置在不在棋盘范围或已经落子,请重新选择!\n");
                        continue;
                    }
                }
                else{
                    printf("输入格式有误,请重新输入!\n");
                    while(getchar() != '\n');
                }
            }
            screenclean();
            boardprint(board,row,col);
            whitestep++;
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == WHITEWIN){
                printf("白方胜利！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            else if(gamestate == PEACE){
                printf("平局！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            bancheck(tempban,board);
        }
}

void debugmode(){//debug模式
    screenclean();
            printf("您选择了Debug模式\n");
            aimode = BLACK;
            printf("棋局开始\n");
            while(gamestate == UNDERWAY){
            while(1){//开发者使用，不考虑输入错误
            emptyboardprint(board);
            printf("请输入坐标,查看对此处的判断情况；输入“0 任意字母”退出查看\n");
            scanf("%d %c",&row,&col);
            if(row == 0){
                break;
            }
            targetrow = BOARDSIZE - row;
            targetcol = col - 'A';
            bancheck(ban,board);
            mark(board,ban,aimode,blackscore,whitescore);
            if(ban[targetrow][targetcol] == BAN){
                printf("此处是黑棋禁手\n");
            }
            else{
                printf("此处不是黑棋禁手\n");
            }
            printf("此处黑棋打分为:%d  白棋的打分为:%d\n",blackscore[targetrow][targetcol],whitescore[targetrow][targetcol]);
            twocheck(board,targetrow,targetcol);
            threecheck(board,targetrow,targetcol);
            fourcheck(board,targetrow,targetcol);
            fivecheck(board,targetrow,targetcol);
            fivepluscheck(board,targetrow,targetcol);
            printf("黑棋活二:%d  ",blacklivetwo);
            printf("白棋活二:%d  ",whitelivetwo);
            printf("黑棋眠二:%d  ",blacksleeptwo);
            printf("白棋眠二:%d\n",whitesleeptwo);
            printf("黑棋活三:%d  ",blacklivethree);
            printf("白棋活三:%d  ",whitelivethree);
            printf("黑棋跳活三:%d  ",blackjumpthree);
            printf("白棋跳活三:%d  ",whitejumpthree);
            printf("黑棋眠三:%d  ",blacksleepthree);
            printf("白棋眠三:%d\n",whitesleepthree);
            printf("黑棋活四:%d  ",blacklivefour);
            printf("白棋活四:%d  ",whitelivefour);
            printf("黑棋冲四:%d  ",blackchargefour);
            printf("白棋冲四:%d  ",whitechargefour);
            printf("黑棋跳冲四:%d  ",blackjumpfour);
            printf("白棋跳冲四:%d\n",whitejumpfour);
            printf("黑棋连五:%d  ",blackfive);
            printf("白棋连五:%d  ",whitefive);
            printf("黑棋长连:%d  ",blackfiveplus);
            printf("白棋长连:%d\n",whitefiveplus);//显示各种数据
    }
    screenclean();
    emptyboardprint(board);
        printf("请黑方落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
        printf("当前黑棋已落%d子,白棋已落%d子\n",blackstep,whitestep);
            while(1){//黑方落子
                goinger = BLACKGO;
                if(scanf("%d %c",&row,&col) == 2){
                    if(1 <= row && row <= BOARDSIZE && 1 <= col - 'A' + 1 && col - 'A' + 1 <= BOARDSIZE && board[BOARDSIZE - row][col - 'A'] == EMPTY){
                        board[BOARDSIZE - row][col - 'A'] = BLACK;
                        break;
                    }
                    else{
                        printf("您选择的位置在不在棋盘范围或已经落子,请重新选择!\n");
                        continue;
                    }
                }
                else{
                    printf("输入格式有误,请重新输入!\n");
                    while(getchar() != '\n');
                }
            }
            screenclean();
            boardprint(board,row,col);
            blackstep++;
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == BLACKWIN){
                printf("黑方胜利！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            else if(gamestate == PEACE){
                printf("平局！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            printf("请白方落子-输入“行 列”,其中行为1-15的数字,列为A-O的大写字母\n");
            printf("当前黑棋已落%d子,白棋已落%d子\n",blackstep,whitestep);
            while(1){//白方落子
                goinger = WHITEGO;
                if(scanf("%d %c",&row,&col) == 2){
                    if(1 <= row && row <= BOARDSIZE && 1 <= col - 'A' + 1 && col - 'A' + 1 <= BOARDSIZE && board[BOARDSIZE - row][col - 'A'] == EMPTY){
                        board[BOARDSIZE - row][col - 'A'] = WHITE;
                        break;
                    }
                    else{
                        printf("您选择的位置在不在棋盘范围或已经落子,请重新选择!\n");
                        continue;
                    }
                }
                else{
                    printf("输入格式有误,请重新输入!\n");
                    while(getchar() != '\n');
                }
            }
            screenclean();
            boardprint(board,row,col);
            whitestep++;
            wincheck(board,goinger,row,col,blackstep,whitestep);
            if(gamestate == WHITEWIN){
                printf("白方胜利！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
            else if(gamestate == PEACE){
                printf("平局！\n即将重新开始游戏\n");
                wait(10000);
                return;
            }
    }
}