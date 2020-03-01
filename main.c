#include <stdint.h>
#include <math.h>
#include "pendulum.h"
#include "window.h"

typedef enum { false = 0, true = 1 } bool;

int main()
{
	const int NUM_PENDULUM = 4;
	const double TIME_DELTA = (double) 1 / 60;
	const int TICK_INTERVAL = TIME_DELTA * 1000;
	const int WIN_WIDTH = 600;
	const int WIN_HEIGHT = 600;
	Pendulum pends[NUM_PENDULUM];
	for (int32_t i = 0; i < NUM_PENDULUM; i++) {
		pends[i] = (Pendulum) { .theta = M_PI / 6, .d_theta = 0, .length = (double) (i+1) / NUM_PENDULUM, .dt = TIME_DELTA };
	}

	Window* window = window_init(WIN_WIDTH, WIN_HEIGHT, "Pendulum");

	int32_t v_length = (WIN_WIDTH / 2 < WIN_HEIGHT) ? WIN_WIDTH / 2 : WIN_HEIGHT;

	bool playing = true;

	Uint32 next_time = SDL_GetTicks() + TICK_INTERVAL;
	while (playing) {
		window_clear(window);
		for (int32_t i = 0; i < NUM_PENDULUM; i++) {
			int32_t x = pendulum_get_x(&pends[i]) * v_length + WIN_WIDTH / 2;
			int32_t y = pendulum_get_y(&pends[i]) * v_length;
			window_draw_line(window, WIN_WIDTH / 2, 0, x, y, 255, 255, 255);
			window_draw_circle(window, x, y, 5, 255, 0, 0);
			pendulum_next_state(&pends[i]);
		}
		window_render(window);
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				window_close(window);
				playing = false;
			}
		}
		SDL_Delay(time_left(next_time));
		next_time += TICK_INTERVAL;
	}
	return 0;
}
