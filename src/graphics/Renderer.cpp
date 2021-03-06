#include "Renderer.hpp"
#include "../IOBots.hpp"

Renderer::Renderer() {
}

Renderer::~Renderer() {
    cleanup();
}

bool Renderer::init() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		fprintf(stderr, "Couldn't init sdl2: %s\n", SDL_GetError());
		return false;
	}

	SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
	if (window == NULL || renderer == NULL) {
		fprintf(stderr, "could not create window or renderer: %s\n", SDL_GetError());
		return false;
	}
    SDL_SetWindowTitle(window, "IOBots");

	screenSurface = SDL_GetWindowSurface(window);
	return true;
}

void Renderer::cleanup(){
	SDL_Quit();
}

void Renderer::draw(){
	SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);

	for(int x = 0; x < 640; x += 20) {
		SDL_RenderDrawLine(renderer, x, 0, x, 480);
	}
	for(int y = 0; y < 480; y+= 20) {
		SDL_RenderDrawLine(renderer, 0, y, 640, y);
	}

	IOBots::bot.render(renderer);

	SDL_RenderPresent(renderer);
}