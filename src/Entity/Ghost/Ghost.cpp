#include "Ghost.h"
#include <stdio.h>

Ghost::Ghost(const char* texture_path, float pos_y) : Entity(texture_path, pos_y)
{
}

Ghost::~Ghost()
{
}

void Ghost::OnCollision()
{
	printf("GHOOOST\n");
}
