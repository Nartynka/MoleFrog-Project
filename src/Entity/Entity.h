#pragma once
#include "../GameObject/GameObject.h"

class Entity : public GameObject
{
public:
	Entity(const char* texture_path, float pos_y = 100.f);
	~Entity();
	
private:
};