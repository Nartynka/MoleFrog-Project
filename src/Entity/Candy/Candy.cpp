#include "Candy.h"
#include <stdio.h>

static int points = 0;

Candy::Candy(const char* texture_path, float pos_y) : Entity(texture_path, pos_y)
{
}

Candy::~Candy()
{
}

void Candy::OnCollision()
{
	points++;
	printf("Points: %i\n", points);

}