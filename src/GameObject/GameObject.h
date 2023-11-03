#pragma once
#include "../Vec2.h"
#include "../Collider/Collider.h"

class GameObject
{
public:
	GameObject(const char* texture_path);
	~GameObject();
	void Draw();
	virtual void Move(float dt);
	virtual bool CheckScreenBounds();
	virtual void OnCollision();
	Collider* collider;
protected:
	struct SDL_Texture* texture;
	Vec2 size;
	Vec2 position = {0, 0};
	Vec2 velocity = {0, 0};
	int speed = 256;
	int jump_speed = 256;
};
