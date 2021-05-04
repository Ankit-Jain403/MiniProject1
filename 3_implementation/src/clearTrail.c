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

void clearTrail() {
    for (int i = 0; i < MAX_TRAIL_LENGTH; i++) {
        trail[i].x = -1;
        trail[i].y = -1;
    }
}
