#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "output.h"

#define WALL '#'
#define PLAYER 'S'
#define FOOD 'F'
#define AIR ' '

#define MAX_TRAIL_LENGTH 1024  // BUFFER_SIZE_X * BUFFER_SIZE_Y

struct block {
    int x;
    int y;
} player, food;
int points;
struct block trail[MAX_TRAIL_LENGTH];
int trail_index = 0;
char key = 0;
void placeFood() {
    do {
        food.x = rand() % BUFFER_SIZE_X;
        food.y = rand() % BUFFER_SIZE_Y;
        if (buffer[food.x][food.y] == AIR) {
            buffer[food.x][food.y] = FOOD;
        }
    } while (buffer[food.x][food.y] != AIR && buffer[food.x][food.y] != FOOD);
}
