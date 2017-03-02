#include "SDL\include\SDL.h"

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_CreateWindowAndRenderer(300, 400, 0, &window, &renderer);
	SDL_Texture* title = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("title.bmp"));
	SDL_Texture* spaceship = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("player.bmp"));
	SDL_Rect r;

	bool run = true;
	while(run) {
		// Input ------------
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type = SDL_QUIT) {
				run = false;
			}
		}

		// Graphics ------------

		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, title, NULL, NULL);
		r = { 0, 0, 63, 58 };
		SDL_RenderCopy(renderer, spaceship, NULL, &r);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderPresent(renderer);
	}

	SDL_Quit();
	return(0);
}