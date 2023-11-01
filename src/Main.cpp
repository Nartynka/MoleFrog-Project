#include <SDL.h>
#include <assert.h>
#include <vector>

#include "Render/Render.h"
#include "Player/Player.h"
#include "Entity/Entity.h"


int main(int argc, char* args[])
{
	float dt = (float)(SDL_GetTicks() / 1000.f);
	float lastTime = 0.f;
	const float DESIRED_DT = 1 / 60.f; // 60 FPS

	int result = SDL_Init(SDL_INIT_VIDEO);
	assert(result == 0 && "SDL could not initialize!");

	RenderInit();

	Player* player = new Player();
	Entity* ghost = new Entity("res/ghost.png");
	Entity* candy = new Entity("res/candy.png", 250);

	std::vector<GameObject*> game_objects;
	game_objects.push_back(player);
	game_objects.push_back(ghost);
	game_objects.push_back(candy);

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
				object->Move(dt);
			}


			DrawFrog();
			DrawMole();
			DrawGround();

			for (GameObject* object : game_objects)
			{
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