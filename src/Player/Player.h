#pragma once
#include "../GameObject/GameObject.h"
#include "../Vec2.h"

class Player : public GameObject
{
public:
	Player();
	~Player();
	
	void HandleInput();
	void OnOutsideScreen(float dt);
	bool CheckScreenBounds() override;
private:
	void Move(float dt) override;
	int player_ground_level;
};
