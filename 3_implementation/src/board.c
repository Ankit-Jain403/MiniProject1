#include "board.h"

/* prints an array */
/* WORKING */
void print_board(char board[][BOARD_X])
{
	for(int y = 0; y < BOARD_Y; y++) {
		for(int x = 0; x < BOARD_X; x++) {
			printf("%c",board[y][x]);
		}
	printf("\r\n");
	}
}

/* initializes array */
/* WORKING */
void init_board(char board[][BOARD_X])	/* it uses macro BOARD_X defined in board.h */
{
	//looping through the board
	for(int y = 0; y < (BOARD_Y); y++) {
		for(int x = 0; x < (BOARD_X); x++) {
			if ((x==0) || (x==(BOARD_X-1)))			/* Side borders */
						board[y][x] = '|';
			else if ((y==0) || ((BOARD_Y-1)==y))	/* Top and bottom borders */
				board[y][x] = '-';
			else 									/* The board space */
				board[y][x] = '0';
		}
	}
}

void update_board(char board[][BOARD_X], snake sn)
{
	snake tmp = sn;
	while (1) {
		board[tmp->y][tmp->x] = '#';
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			break;
	}
}
