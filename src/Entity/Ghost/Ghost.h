#pragma once
#include "../Entity.h"

class Ghost : public Entity
{
public:
	Ghost(const char* texture_path, float pos_y = 100.f);
	~Ghost();
	void OnCollision() override;
private:

};