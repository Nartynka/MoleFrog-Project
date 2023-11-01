#include "GameObject.h"

#include "../Render/Render.h"
#include <SDL_image.h>

GameObject::GameObject(const char* texture_path)
{
	CreateTexture(texture_path, &texture, size);
}


GameObject::~GameObject()
{
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
}
