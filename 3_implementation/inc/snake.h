#include <stdlib.h>

#ifndef SNAKE_H
#define SNAKE_H

/* snake structure */
struct segment{
	int x;
	int y;
	struct segment* next;
};
typedef struct segment segment;	/*  BASICALLY :        */
typedef segment* snake;			/*  snake = segment*   */

#endif

segment* create_segment(int x, int y);
segment* prepend(snake sn, segment* sg);
segment* prepend_xy(snake sn, int x, int y);
void append(snake sn, segment* sg);
int append_xy(snake sn, int x, int y);
segment* last_segment(snake s);
int intersect_snake(snake s);
void delete_last_segment(snake s);
segment* move_snake(snake s, int move_x, int move_y);
int check_snake(snake s, int x, int y);
