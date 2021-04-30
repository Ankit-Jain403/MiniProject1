#include"snake.h"
#include<stdbool.h>
#include<stdio.h>
#include<time.h>
#include<SDL2/SDL.h>
// Init, close and update SDL pre-functions
void draw_game(struct Game* my_game);

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
// Draw all game
void draw_game(struct Game* my_game) {
	SDL_Rect apple = {
		my_game->apple_pos[0] * SQUARE_SIZE, 
		my_game->apple_pos[1] * SQUARE_SIZE, 
		SQUARE_SIZE, SQUARE_SIZE
	};
	
	// Clear screen
	SDL_SetRenderDrawColor(w_renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(w_renderer);
	// Draw snake
	SDL_SetRenderDrawColor(w_renderer, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);
	for(int i = 0; i < (my_game->player.lenght); i++){
		SDL_Rect snake_part = {
			my_game->player.tailPos[i][0] * SQUARE_SIZE,
			my_game->player.tailPos[i][1] * SQUARE_SIZE,
			SQUARE_SIZE, SQUARE_SIZE
		};
		SDL_RenderFillRect(w_renderer, &snake_part);
	}
	// Draw apple
	SDL_SetRenderDrawColor(w_renderer, 0xFF, 0x00, 0x00, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(w_renderer, &apple);
	// Draw on screen
	SDL_RenderPresent(w_renderer);
}
