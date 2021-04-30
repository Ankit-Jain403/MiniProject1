#include"snake.h"
#include<stdbool.h>
#include<stdio.h>
#include<time.h>
#include<SDL2/SDL.h>
// Init, close and update SDL pre-functions
void update_game(struct Game* my_game);


// Game constants
const int SCREEN_SIZE = 500;
const int SQUARE_SIZE = SCREEN_SIZE / GRID_SIZE;
const int UPDATE_FPS = 10;
const int TICKS_PER_FRAME = 1000 / UPDATE_FPS;
// Window variables
SDL_Window* window = NULL;
SDL_Renderer* w_renderer = NULL;
bool game_running = true;
SDL_Event e;
// Update game values
void update_game(struct Game* my_game) {
	// Move the snake tail unless the head
	for(int i = (my_game->player.lenght - 1); i > 0; i--) {
		my_game->player.tailPos[i][0] = 
			my_game->player.tailPos[i - 1][0];
		my_game->player.tailPos[i][1] = 
			my_game->player.tailPos[i - 1][1];
	};
	// Update player position
	my_game->player.tailPos[0][0] += my_game->player.x_dir;
	my_game->player.tailPos[0][1] += my_game->player.y_dir;
	// If the player is on the border of the screen
	if(my_game->player.tailPos[0][0] < 0) {
		my_game->player.tailPos[0][0] = GRID_SIZE - 1; 
	}
	else if(my_game->player.tailPos[0][0] >= GRID_SIZE){
		my_game->player.tailPos[0][0] = 0;
	}
	if(my_game->player.tailPos[0][1] < 0) {
		my_game->player.tailPos[0][1] = GRID_SIZE - 1; 
	}
	else if(my_game->player.tailPos[0][1] >= GRID_SIZE) {
		my_game->player.tailPos[0][1] = 0;
	}
	// Check if the player is on the apple
	if(my_game->player.tailPos[0][0] == my_game->apple_pos[0]){
		if(my_game->player.tailPos[0][1] == my_game->apple_pos[1]){
			my_game->player.lenght++;
			my_game->apple_pos[0] = rand() % 20;
			my_game->apple_pos[1] = rand() % 20;
		}
	}
	for(int i = 1; i < my_game->player.lenght; i++) {
		if(my_game->player.tailPos[i][0] == my_game->player.tailPos[0][0]){
			if(my_game->player.tailPos[i][1] == my_game->player.tailPos[0][1]){
				create_game(&(*my_game));
			}
		}
	};
}
