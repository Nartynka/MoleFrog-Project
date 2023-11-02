#pragma once
#include "../Vec2.h"

class Collider
{
public:
	Collider(Vec2 object_size, Vec2 object_position);
	~Collider();
	bool CheckCollision(Collider* other_collider);
	void UpdatePosition(Vec2 position);
private:
	Vec2 size;
	Vec2 position;
};