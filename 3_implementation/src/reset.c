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
void reset() {
    // Reset input
    key = 0;
    last_input = 0;

    // Initialize game field
    clear(AIR);
    createGameField();
    clearTrail();
    player.x = BUFFER_SIZE_X / 2;
    player.y = BUFFER_SIZE_Y / 2;
    points = 0;
    placeFood();
}
