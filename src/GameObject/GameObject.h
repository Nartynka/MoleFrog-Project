#pragma once
#include "../Vec2.h"

class GameObject
{
public:
	GameObject(const char* texture_path);
	~GameObject();
	void Draw();
	void Move(float dt);
protected:
	struct SDL_Texture* texture;
	Vec2 size;
	Vec2 position = {0, 0};
	Vec2 velocity = {0, 0};
	int speed = 256;
	int jump_speed = 256;
	const int GROUND_LEVEL = 400;
};
