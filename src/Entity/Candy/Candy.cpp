#include "Candy.h"
#include "../../Globals.h"

#include <cstdio>

Candy::Candy(float side, float pos_y, float vel_x, const char* texture_path) : Entity(texture_path, side, pos_y, vel_x)
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