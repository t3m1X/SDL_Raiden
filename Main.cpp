#include "SDL\include\SDL.h"


int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("SDL Raiden", 100, 100, 300, 400, NULL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_PRESENTVSYNC);

	SDL_Texture* title = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("title.bmp"));
	SDL_Texture* spaceship = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("player.bmp"));
	SDL_Rect r;

	enum y_State {
		KEY_DOWN = 0,
		KEY_UP,
		KEY_REPEAT
	};

	int ship_x = 0, ship_y = 0;


	bool run = true;
	while(run) {
		// Input ------------
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT :
					run = false;
					break;
			case SDL_KEYDOWN :
					switch (event.key.keysym.scancode) {
					case SDL_SCANCODE_RIGHT:
						ship_x += 5;
						break;

					case SDL_SCANCODE_LEFT:
						ship_x -= 5;
						break;

					case SDL_SCANCODE_UP:
						ship_y -= 5;
						break;

					case SDL_SCANCODE_DOWN:
						ship_y += 5;
						break;

					case SDL_SCANCODE_ESCAPE: 
						run = false;
						break;
					}
					break;
			}

		}
		//if (state[])

		// Graphics ------------

		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, title, NULL, NULL);
		r = { ship_x, ship_y, 63, 58 };
		SDL_RenderCopy(renderer, spaceship, NULL, &r);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderPresent(renderer);
	}

	SDL_Quit();
	return(0);
}