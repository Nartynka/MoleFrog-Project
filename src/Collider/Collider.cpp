#include "Collider.h"

Collider::Collider(Vec2 object_size, Vec2 object_position)
{
	position = object_position;
	size = object_size;
}

Collider::~Collider()
{

}

bool Collider::CheckCollision(Collider* other_collider)
{
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = position.x;
	rightA = position.x + size.x;
	topA = position.y;
	bottomA = position.y + size.y;

	//Calculate the sides of rect B
	leftB = other_collider->position.x;
	rightB = other_collider->position.x + other_collider->size.x;
	topB = other_collider->position.y;
	bottomB = other_collider->position.y + other_collider->size.y;

	if (bottomA <= topB)
		return false;

	if (topA >= bottomB)
		return false;

	if (rightA <= leftB)
		return false;

	if (leftA >= rightB)
		return false;

	//If none of the sides from A are outside B
	return true;
}

void Collider::UpdatePosition(Vec2 position)
{
	this->position = position;
}
