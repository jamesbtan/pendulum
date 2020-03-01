#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <SDL2/SDL.h>

typedef struct {
	int32_t width;
	int32_t height;
	SDL_Renderer *renderer;
	SDL_Window *window;
} Window;

void window_init(Window *window, int32_t width, int32_t height, char *title);

void window_draw_circle(Window *window, int32_t x, int32_t y, int32_t rad, int32_t r, int32_t g, int32_t b);
void window_draw_line(Window *window, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t r, int32_t g, int32_t b);
void window_draw_box(Window *window, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t r, int32_t g, int32_t b);

void window_clear(Window *window);
void window_render(Window *window);
void window_close(Window *window);

Uint32 time_left(Uint32 next_time);

#endif
