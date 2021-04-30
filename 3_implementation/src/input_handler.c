#include"snake.h"
#include<stdbool.h>
#include<stdio.h>
#include<time.h>
#include<SDL2/SDL.h>
// Init, close and update SDL pre-functions
void input_handler(struct Snake* player);

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
// Handle inputs
void input_handler(struct Snake* player) {
	while (SDL_PollEvent(&e) != 0) {
		if(e.type == SDL_QUIT)
			game_running = false;
	}
	const Uint8* current_keys = SDL_GetKeyboardState(NULL);
	if(current_keys[SDL_SCANCODE_W] && (player->y_dir == 0)) {
		player->x_dir = 0;
		player->y_dir = -1;
	}
	else if(current_keys[SDL_SCANCODE_S] && (player->y_dir == 0)) {
		player->x_dir = 0;
		player->y_dir = 1;
	}
	else if(current_keys[SDL_SCANCODE_A] && (player->x_dir == 0)) {
		player->x_dir = -1;
		player->y_dir = 0;
	}
	else if(current_keys[SDL_SCANCODE_D] && (player->x_dir == 0)) {
		player->x_dir = 1;
		player->y_dir = 0;
	}
}
