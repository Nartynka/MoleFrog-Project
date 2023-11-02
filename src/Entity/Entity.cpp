#include "Entity.h"
#include "../Globals.h"

Entity::Entity(const char* texture_path, float pos_x, float pos_y, float vel_x) : GameObject(texture_path)
{
	velocity = { vel_x, 0 };
	if(pos_x == 0)
		position = { 0.f, pos_y };
	else
		position = { SCREEN_WIDTH, pos_y };

	speed = 100;
}

Entity::~Entity()
{
}