#include "Player.h"
#include "../Render/Render.h"
#include <SDL_image.h>

Player::Player() : GameObject("res/Player.jpg")
{
	player_ground_level = GROUND_LEVEL - size.y;
	position = { 0.f, (float)player_ground_level };
	speed = 512;
}

Player::~Player()
{
}

void Player::HandleInput()
{
	const Uint8* input_state = SDL_GetKeyboardState(NULL);

	if (input_state[SDL_SCANCODE_A] || input_state[SDL_SCANCODE_LEFT])
	{
		velocity.x = -1;
	}
	else if (input_state[SDL_SCANCODE_D] || input_state[SDL_SCANCODE_RIGHT])
	{
		velocity.x = 1;
	}
	else
	{
		velocity.x = 0;
	}

	if (input_state[SDL_SCANCODE_SPACE])
	{
		velocity.y = -1;
	}
	else if(position.y != player_ground_level)
	{
		velocity.y = 1;
	}
	else
	{
		velocity.y = 0;
	}
}
