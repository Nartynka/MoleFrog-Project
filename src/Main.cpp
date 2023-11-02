#include <SDL.h>
#include <cassert>
#include <vector>
#include <ctime>

#include "Render/Render.h"
#include "Player/Player.h"
#include "Entity/Entity.h"
#include "Entity/Candy/Candy.h"
#include "Entity/Ghost/Ghost.h"
#include "EntitySpawner/EntitySpawner.h"


int main(int argc, char* args[])
{
	float dt = (float)(SDL_GetTicks() / 1000.f);
	float lastTime = 0.f;
	const float DESIRED_DT = 1 / 60.f; // 60 FPS

	srand((unsigned)time(nullptr));

	int result = SDL_Init(SDL_INIT_VIDEO);
	assert(result == 0 && "SDL could not initialize!");

	RenderInit();

	Player* player = new Player();

	std::vector<GameObject*> game_objects;
	std::vector<Entity*> entities;

	game_objects.push_back(player);

	EntitySpawner* spawner = new EntitySpawner();
	const float SPAWN_RATE = 1.f;
	float spawn_timeout = SPAWN_RATE;

	bool quit = false;
	SDL_Event event;
	
	while (!quit)
	{
		dt = (SDL_GetTicks() - lastTime) / 1000;
		if (dt >= DESIRED_DT)
		{
			while (SDL_PollEvent(&event) != 0)
			{
				if (event.type == SDL_QUIT)
					quit = true;
			}

		
			player->HandleInput();

			for (GameObject* object : game_objects)
			{
				if(object)
					object->Move(dt);
			}

			for (Entity* entity : entities)
			{
				if (entity == nullptr)
					continue;

				bool is_colliding = player->collider->CheckCollision(entity->collider);
				if (is_colliding)
				{
					// @TODO destroy when entities go outside the screen
					// @TODO block player from going outside the screen
					entity->OnCollision();
					entities.erase(std::find(entities.begin(), entities.end(), entity));
					game_objects.erase(std::find(game_objects.begin(), game_objects.end(), entity));
					delete entity;
				}
			}

			if (spawn_timeout <= 0.f)
			{
				Entity* spawned_entity = spawner->Spawn();
				game_objects.push_back(spawned_entity);
				entities.push_back(spawned_entity);
				spawn_timeout = SPAWN_RATE;
			}
			else
			{
				spawn_timeout -= dt;
			}

			DrawFrog();
			DrawMole();
			DrawGround();

			for (GameObject* object : game_objects)
			{
				if(object)
					object->Draw();
			}
			
			Render();

			lastTime = (float)SDL_GetTicks();

		}
	}

	RenderTerminate();
	SDL_Quit();
	return 0;
}