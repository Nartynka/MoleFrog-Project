#include "Player.h"
#include "../Globals.h"
#include <SDL.h>
#include <stdio.h>

Player::Player() : GameObject("res/Player.jpg")
{
	player_ground_level = GROUND_LEVEL - (int)size.y;
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
	else if(position.y < player_ground_level)
	{
		velocity.y = 1;
	}
	else
	{
		velocity.y = 0;
	}
}

void Player::OnOutsideScreen(float dt)
{
	position.x -= velocity.x * speed * dt;
	position.y -= velocity.y * speed * dt;
	//velocity = {0,0};
}

bool Player::CheckScreenBounds()
{
	if (position.x < 0 || position.x + size.x > SCREEN_WIDTH || position.y < 0 || position.y + size.y > SCREEN_HEIGHT)
	{
		return true;
	}

	return false;
}

void Player::Move()
{
	if (velocity.x != 0)
	{
		position.x += velocity.x * speed * dt;
	}

	
	if (velocity.y != 0)
	{
	//    player is jumping          player is falling
		if(velocity.y < 0 || position.y <= player_ground_level)
			position.y += velocity.y * jump_speed * dt;
	}

	collider->UpdatePosition(position);
}
