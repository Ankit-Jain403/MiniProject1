#include <stdio.h>
#include "snake.h"

#ifndef BOARD_H
#define BOARD_H

/* Board size */
#define BOARD_X 40
#define BOARD_Y 20

#endif

void print_board(char board[][BOARD_X]);
void init_board(char board[][BOARD_X]);
void update_board(char board[][BOARD_X], snake sn);
