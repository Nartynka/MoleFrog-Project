#include "Entity.h"
#include "../Render/Render.h"

Entity::Entity(const char* texture_path, float pos_y) : GameObject(texture_path)
{
	velocity = { -1, 0 };
	position = { SCREEN_WIDTH, pos_y };
	speed = 100;
}

Entity::~Entity()
{
}