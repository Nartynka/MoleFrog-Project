#pragma once
#include "../Entity.h"

class Candy : public Entity
{
public:
	Candy(float side = 0.f, float pos_y = 250.f, float vel_x = -1, const char* texture_path = "res/candy.png");
	~Candy();
	void OnCollision() override;
private:

};