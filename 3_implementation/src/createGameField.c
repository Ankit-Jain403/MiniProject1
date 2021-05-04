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
void createGameField() {
    // Walls
    for (int x = 0; x < BUFFER_SIZE_X; x++) {
        buffer[x][0] = WALL;
        buffer[x][BUFFER_SIZE_Y - 1] = WALL;
    }
    for (int y = 0; y < BUFFER_SIZE_Y; y++) {
        buffer[0][y] = WALL;
        buffer[BUFFER_SIZE_X - 1][y] = WALL;
    }
}
