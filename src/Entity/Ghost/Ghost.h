#pragma once
#include "../Entity.h"

class Ghost : public Entity
{
public:
	Ghost(float side = 0.f, float pos_y = 100.f, float vel_x = -1, const char* texture_path = "res/ghost.png");
	~Ghost();
	void OnCollision() override;
private:

};