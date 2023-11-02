#include "Candy.h"
#include <stdio.h>

Candy::Candy(const char* texture_path, float pos_y) : Entity(texture_path, pos_y)
{
}

Candy::~Candy()
{
}

void Candy::OnCollision()
{
	printf("CANDDDDDDY\n");
}
