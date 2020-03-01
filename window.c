#include "window.h"
#include <SDL2/SDL2_gfxPrimitives.h>

struct Window {
	int32_t width;
	int32_t height;
	SDL_Renderer *renderer;
	SDL_Window *window;
};

Window* window_init(int32_t width, int32_t height, char *title) {
	Window* window = malloc(sizeof(Window));
	window->window = SDL_CreateWindow(title, 0, 0, width, height, SDL_WINDOW_SHOWN);
	if (window->window == NULL) {
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
	}
	window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (window->renderer == NULL) {
		printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
	}
	return window;
}

void window_draw_circle(Window *window, int32_t x, int32_t y, int32_t rad, int32_t r, int32_t g, int32_t b)
{
	filledCircleRGBA(window->renderer, x, y, rad, r, g, b, 255);
}

void window_draw_line(Window *window, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t r, int32_t g, int32_t b)
{
	lineRGBA(window->renderer, x1, y1, x2, y2, r, g, b, 255);
}

void window_draw_box(Window *window, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t r, int32_t g, int32_t b)
{
	boxRGBA(window->renderer, x1, y1, x2, y2, r, g, b, 255);
}

void window_clear(Window *window)
{
	SDL_SetRenderDrawColor(window->renderer, 0, 0, 0, 255);
	SDL_RenderClear(window->renderer);
}

void window_render(Window *window)
{
	SDL_RenderPresent(window->renderer);
}

void window_close(Window *window)
{
	SDL_DestroyRenderer(window->renderer);
	SDL_DestroyWindow(window->window);
	SDL_Quit();
}

Uint32 time_left(Uint32 next_time)
{
	Uint32 now;
	now = SDL_GetTicks();
	if (next_time <= now)
		return 0;
	else
		return next_time - now;
}
