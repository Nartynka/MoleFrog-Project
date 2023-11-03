#include "GameObject.h"

#include "../Render/Render.h"
#include "../Globals.h"
#include <cstdio>

GameObject::GameObject(const char* texture_path)
{
	CreateTexture(texture_path, &texture, size);
	collider = new Collider(size, position);
}


GameObject::~GameObject()
{
	delete collider;
}

void GameObject::Draw()
{
	DrawObject(texture, size, position);
}

void GameObject::Move(float dt)
{
	if (velocity.x != 0)
	{
		position.x += velocity.x * speed * dt;
	}
	collider->UpdatePosition(position);
}

bool GameObject::CheckScreenBounds()
{
	if (position.x + size.x < 0 || position.x > SCREEN_WIDTH || position.y < 0 || position.y > SCREEN_HEIGHT)
	{
		return true;
	}

	return false;
}

void GameObject::OnCollision()
{
}
