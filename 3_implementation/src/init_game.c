#include"snake.h"
#include<stdbool.h>
#include<stdio.h>
#include<time.h>
#include<SDL2/SDL.h>
// Init, close and update SDL pre-functions
bool init_game();

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

// Init SDL
bool init_game() {
	// Sucess flag
	bool sucess = false;
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! ERROR: %s\n", SDL_GetError());
	}
	else {
		// Create window
		window = SDL_CreateWindow(
			"Snake in C", 
			SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED,
			SCREEN_SIZE,
			SCREEN_SIZE,
			SDL_WINDOW_SHOWN
		);
		if(window == NULL) {
			printf("Window could not be created! ERROR: %s", SDL_GetError());
		}
		else {
			// Create window surface
			w_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if(w_renderer == NULL){
				printf("SDL could not create a renderer! ERROR: %s", SDL_GetError());
			}
			else {
				SDL_SetRenderDrawColor(w_renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
				SDL_RenderPresent(w_renderer);
				// Sucess!!
				sucess = true;
			}
		}
	}
	return sucess;
}
