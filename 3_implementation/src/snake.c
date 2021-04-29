/*
 *	a possible implementation of a snake as a linked list
 *	basic list functions 
 *
 *	snake works as a pointer to the whole structure, while segment represents a single tile,
 *	the (x, y) of each segment on the board, with a pointer(connection) to the next one
 *
 *	when i move the snake, instead of redoing the whole structure i simply add a new segment in the next position
 *	and delete the last segment, when the snake eats i just add the segment without removing anything
 *
 *	to check for intersections with itself i just check if the head(x,y) intersects with any segment, might work
 *	in the same way with the board
 */

//
// TODO: test all the functions
//		 check if function's parameter isn't NULL !!
//

#include "snake.h"

/* --- list manipulation --- */

/* returns a pointer to new segment */
/* WORKING */
segment* create_segment(int x, int y)
{
	segment *new = malloc(sizeof(segment));
	new->x = x;
	new->y = y;
	new->next = NULL;
	return new;
}

/* adds a segment at the beginning */
/* WORKING */
segment* prepend(snake sn, segment *sg)
{
	sg->next = sn;
	return sg;
}

segment* prepend_xy(snake sn, int x, int y)
{
	snake tmp;
	tmp = create_segment(x, y);
	tmp->next = sn;
	return tmp;
}

/* adds a segment at the end */
/* WORKING */
void append(snake sn, segment *sg)
{
	snake tmp = sn;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = sg;
	sg->next = NULL;
}

/* appends a segment with given xy, returns 0 if a segment is already there */
/* WORKING */
int append_xy(snake sn, int x, int y)
{
	segment* p = sn;
	/* check each segment then append new at the end */
	while(p->next != NULL){
		if(p->x == x && p->y == y)
			return 0;
		else
			p = p->next;
	}
	
	/* might use append() too */
	segment* new = malloc(sizeof(segment));
	new->x = x;
	new->y = y;
	new->next = NULL;
	p->next = new;

	return 1;
}

/* returns a pointer to the last segment, the snake's tail */
/* WORKING */
segment* last_segment(snake s)
{
	if(s->next == NULL)
		return s;
	else
		return last_segment(s->next);
}

/* returns 1 if snake intersects with itself */
/* WORKING */
int intersect_snake(snake s)
{
	snake tmp = s->next;
	while(tmp){
		if(s->x == tmp->x && s->y == tmp->y)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

/* WORKING */
void delete_last_segment(snake s)
{
	snake p = s;
	while(p->next->next != NULL){
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
}

/* append the new head position, remove the tail position, return pointer to the updated structure */
/* WORKING */
segment* move_snake(snake s, int move_x, int move_y)	// MAYBE ADD intersect_snake() TO IT
{
	segment *tmp = create_segment(move_x, move_y);
	s = prepend(s, tmp);
	delete_last_segment(s);
	return s;
}

/* returns 1 if a segment is present on the given (x,y) */
/* WORKING */
int check_snake(snake s, int x, int y)
{
	snake tmp = s;
	while(tmp){
		if(tmp->x == x && tmp->y == y)
			return 1;
		else
			tmp = tmp->next;
	}
	return 0;
}
