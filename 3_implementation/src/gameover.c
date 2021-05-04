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
void gameover() {
    printf("\n\nGAME OVER\nYour score: %d\n", points);

    // Ask whether to reset or not:
    while (key != 'y' && key != 'n') {
        printf("Reset? [y/n]: ");
        key = getchar();
        printf("\n");
    }
    switch (key) {
        case 'y':
            reset();
            printf("\n");
            break;
        case 'n':
            key = 'q';
            printf("\n\nHere, have a look at your death:");
            break;
        default:
            printf(" Illegal Input. How did you get here anyway?!\n");
            break;
    }
}
