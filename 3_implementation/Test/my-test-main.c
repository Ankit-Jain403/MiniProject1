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
int main(int argc, char const *argv[]) {
    // Seed the random generator
    srand(time(NULL));

    // Setup input
    setupEnterAvoidance();

    // Initialize game
    reset();

    // Game loop
    while (key != 'q') {
        // Get Input
        key = readInput();

        // Check for reset key
        if (key == 'r') {
            reset();
            continue;
        }

        if (points > 0) {
            // Remove old trail block
            buffer[trail[trail_index].x][trail[trail_index].y] = AIR;
        }

        // Replace old player position with wall (trail)
        buffer[player.x][player.y] = (points > 0) ? WALL : AIR;
        trail[trail_index].x = player.x;
        trail[trail_index].y = player.y;

        if (points > 0) {
            // Iterate through trail array
            trail_index++;
            if (trail_index >= points) {
                trail_index = 0;
            }
        }

        // Update player position
        switch (key) {
            case 'w':
                player.y--;
                break;
            case 's':
                player.y++;
                break;
            case 'a':
                player.x--;
                break;
            case 'd':
                player.x++;
                break;
            default:
                break;
        }

        // Check new player position for wall
        if (buffer[player.x][player.y] == WALL) {
            gameover();
        }

        // Check new player position for food
        char replacefood = 0;
        if (buffer[player.x][player.y] == FOOD) {
            points++;
            replacefood = 1;
        }

        // Replace new position with player
        buffer[player.x][player.y] = PLAYER;

        // If food has been eaten, place new food
        if (replacefood) {
            placeFood();
        }

        // Print output
        printBuffer();
        printf("\nPoints: %d\n", points);
    }

    printf("\n");
    return 0;
}
