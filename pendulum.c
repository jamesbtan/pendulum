#include "pendulum.h"
#include <math.h>

void pendulum_next_state(Pendulum *pendulum)
{
	pendulum->d_theta += -9.8 / pendulum->length * sin(pendulum->theta) * pendulum->dt;
	pendulum->theta += pendulum->d_theta * pendulum->dt;
}

double pendulum_get_x(Pendulum *pendulum)
{
	return pendulum->length * sin(pendulum->theta);
}

double pendulum_get_y(Pendulum *pendulum)
{
	return pendulum->length * cos(pendulum->theta);
}
