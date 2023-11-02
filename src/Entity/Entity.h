#pragma once
#include "../GameObject/GameObject.h"

class Entity : public GameObject
{
public:
	Entity(const char* texture_path, float pos_x, float pos_y, float vel_x);
	~Entity();
	virtual void OnCollision() = 0;
};