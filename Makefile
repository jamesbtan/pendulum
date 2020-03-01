CC=gcc
CFLAGS=-lSDL2 -lSDL2_gfx -lm
CFLAGS+=-Wall -Wextra -pedantic
CFLAGS+=-Werror -Wshadow -Os
DEPS=pendulum.h window.h
OBJ=main.o pendulum.o window.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pendulum: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o pendulum
