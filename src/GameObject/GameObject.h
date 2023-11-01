#pragma once
#include "../Vec2.h"

class GameObject
{
public:
	GameObject(const char* texture_path, Vec2 pos = {0,0});
	~GameObject();
	void Draw();

private:
	struct SDL_Texture* texture;
	Vec2 size;
	Vec2 position;
};
