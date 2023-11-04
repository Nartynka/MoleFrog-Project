#include "Ghost.h"
#include <cstdio>
#include "..\..\Globals.h"

Ghost::Ghost(float side, float pos_y, float vel_x, const char* texture_path) : Entity(texture_path, side, pos_y, vel_x)
{
}

Ghost::~Ghost()
{
}

void Ghost::OnCollision()
{
	game_over = true;
}
