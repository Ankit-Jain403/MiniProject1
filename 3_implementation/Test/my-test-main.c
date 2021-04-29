#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "user_input.h"
#include "board.h"
#include "snake.h"

int main(void)
{
	/* The board itself */
	char  board[BOARD_Y][BOARD_X];
	
	/* Variable to store user's input */
	char direction = '\0';
	
	/* Snake */
	snake my_sn;

	/* Creates the start point, which is always in the middle */
	my_sn = create_segment((BOARD_X % 2 == 0 ? BOARD_X / 2 : BOARD_X + 1 / 2), (BOARD_Y % 2 == 0 ? BOARD_Y / 2 : (BOARD_Y + 1) / 2));

	/* Clears the terminal to start the game :) */
	system("clear");

	/* Initializes board */
	init_board(board);

	/* Draws snake body into the board */
	update_board(board, my_sn);

	/* Prints the board */
	print_board(board);

	/* Enters 'special' mode of terminal */
	entergamemode();

	/* Game life */
	while (1) {
		
		/* Gets input from the user */
		get_input(&direction);

		/* Checks the input, then move the snake:
												Ate food - just prepend one block
												Otherwise - move the snake to the direction */
		switch (toupper(direction)) {

			case('W'):
				if(0) {		//  !!  Must create food and check if snake ate it in these if statements !!
					my_sn = prepend_xy(my_sn, my_sn->x, my_sn->y - 1);
				}
				else {
					my_sn = move_snake(my_sn, my_sn->x, my_sn->y - 1);
				}
				break;

			case('S'):
				if(0) {
					my_sn = prepend_xy(my_sn, my_sn->x, my_sn->y + 1);
				}
				else {
					my_sn = move_snake(my_sn, my_sn->x, my_sn->y + 1);
				}
				break;

			case('D'):
				if(0) {
					my_sn = prepend_xy(my_sn, my_sn->x + 1, my_sn->y);
				}
				else {
					my_sn = move_snake(my_sn, my_sn->x + 1, my_sn->y);
				}
				break;

			case('A'):
				if(0) {
					my_sn = prepend_xy(my_sn, my_sn->x - 1, my_sn->y);
				}
				else {
					my_sn = move_snake(my_sn, my_sn->x - 1, my_sn->y);
				}
				break;
		}

		/* Clears the terminal */
		system("clear");

		/* Initializes (cleares) the board */
		init_board(board);

		/* Draws updated body to board */
		update_board(board, my_sn);

		/* Prints updated board */
		print_board(board);
	}

	/* Exits 'special' mode of terminal */
	endgamemode();

	return 0;
}
