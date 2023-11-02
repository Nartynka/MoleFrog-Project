#pragma once
#include "../Entity.h"

class Candy : public Entity
{
public:
	Candy(const char* texture_path, float pos_y = 100.f);
	~Candy();
	void OnCollision() override;
private:

};