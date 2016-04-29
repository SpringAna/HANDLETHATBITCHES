#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct int tray
{
	size_t w;
	size_t h;
	char *data;
}

struct int pos
{
	size_t x;
	size_t y;	
}

void create_tray(struct tray *self, size_t width, size_t height)
{
	self->w=width;
	self->h=height;
	self->data=calloc(weight*height,sizeof(char));
}

void add_wall(struct tray *self, size_t x, size_t y, bool enemy, bool rock)
{
	if(rock==true)
	{
		self->data[x][y]='R'; //we are placing a rock
	}
	else
	{
		enemy=true;
	}
	if(enemy==false)
	{
		self->data[x][y]='W'; //we are placing our wall
	}
	if(enemy==true)
	{				
		self->data[x][y]='X'; //we can't place a wall anymore
	}
}

bool verify_pos(struct tray *self, size_t x, size_t y) //show if the position chosen is free
{
	if(self->data[x][y]=="R"||self->data[x][y]=="X"||self->data[x][y]=="W")
	{
		return false;
	}
}

/*
	Le programme sera capable de 
		-calculer où poser les murs à chaque tour
		-calculer l'ensemble des cases sur quoi on peut poser les murs
		-calculer la case la plus adaptée à notre stratégie
*/
int main() {
	char buf[BUFSIZE];
	struct tray self;

	// get the width
	fgets(buf, BUFSIZE, stdin);
	int width = atoi(buf);

	// get the height
	fgets(buf, BUFSIZE, stdin);
	int height = atoi(buf);

	create_tray(self, width, height);

	// get the initial x
	fgets(buf, BUFSIZE, stdin);
	int x = atoi(buf);

	// get the initial y
	fgets(buf, BUFSIZE, stdin);
	int y = atoi(buf);

	add_wall(self, x, y, false, false);

	// initialize the state of the game
	for (;;) {
		// play
		// choose a new x and y
		puts("WALL"); // or "PASS"
		printf("%i %i\n", x, y);

		// get the response: WALL, ENEMY, ROCK, FINISH or ERROR
		fgets(buf, BUFSIZE, stdin);

		// update the state of the game
	}
	return 0;
}
