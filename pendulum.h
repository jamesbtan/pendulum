#ifndef _PENDULUM_H_
#define _PENDULUM_H_

typedef struct {
	double theta;
	double d_theta;
	double length;
	double dt;
} Pendulum;

void pendulum_next_state(Pendulum *pendulum);
double pendulum_get_x(Pendulum *pendulum);
double pendulum_get_y(Pendulum *pendulum);

#endif
