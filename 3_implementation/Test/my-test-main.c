#include"snake.h"
#include<stdbool.h>
#include<stdio.h>
#include<time.h>
#include<SDL2/SDL.h>

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

// Main function lol
int main() {
	srand(time(NULL));
	// Init Game
	if(!init_game())
		return 1;
	struct Game game;
	create_game(&game);

	// Timer
	Uint32 capTimer;
	while(game_running) {
		// Ticks per frame
		capTimer = SDL_GetTicks();
		// Game logic
		input_handler(&(game.player));
		update_game(&game);
		draw_game(&game);
		// Frame cap
		int frameTicks = SDL_GetTicks() - capTimer;
		if(frameTicks < TICKS_PER_FRAME) {
			SDL_Delay(TICKS_PER_FRAME - frameTicks);
		}
	}
	// End game and destroy the window
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(w_renderer);
	SDL_Quit();
    return 0;
}
