#include "EntitySpawner.h"
#include "../Globals.h"
#include "../Entity/Candy/Candy.h"
#include "../Entity/Ghost/Ghost.h"
#include "../Entity/Entity.h"
#include <cstdlib>
#include <cstdio>

EntitySpawner::EntitySpawner()
{
}

EntitySpawner::~EntitySpawner()
{
}

Entity* EntitySpawner::Spawn()
{
	float random_side = rand() % 2;
	float random_height = rand() % (SCREEN_HEIGHT - GROUND_LEVEL) + 1;
	int random_entity = rand() % 2;

	Entity* spawned_entity;
	if (random_entity % 2 == 0)
	{
		spawned_entity = new Candy(random_side, random_height, random_side ? -1 : 1);
	}
	else
	{
		spawned_entity = new Ghost(random_side, random_height, random_side ? -1 : 1);
	}
	return spawned_entity;
}
