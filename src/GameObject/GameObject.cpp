#include "GameObject.h"

#include "../Render/Render.h"

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
