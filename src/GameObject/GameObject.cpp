#include "GameObject.h"

#include "../Render/Render.h"
#include <SDL_image.h>

GameObject::GameObject(const char* texture_path, Vec2 pos)
{
	CreateTexture(texture_path, &texture, size);
	position = pos;
}


GameObject::~GameObject()
{
}

void GameObject::Draw()
{
	DrawObject(texture, size, position);
}
