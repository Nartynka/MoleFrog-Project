#include "Render.h"
#include "../Globals.h"

#include <SDL.h>
#include <SDL_image.h>
#include <cassert>
#include <stdio.h>


SDL_Window* GetWindow()
{
	// Window has to be stored somewhere because we have to destroy it at the end
	static SDL_Window* window;

	if (!window)
	{
		window = SDL_CreateWindow("MoleFrog", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		assert(window != nullptr && "Window could not be created!");
	}

	return window;
}

SDL_Renderer* GetRenderer()
{
	static SDL_Renderer* renderer;

	if (!renderer)
	{
		renderer = SDL_CreateRenderer(GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		assert(renderer != nullptr && "Renderer could not be created!");
	}

	return renderer;
}

void RenderInit()
{
	GetWindow();
	GetRenderer();
}

void RenderTerminate()
{
	SDL_DestroyWindow(GetWindow());
}

void Render()
{
	SDL_SetRenderDrawColor(GetRenderer(), 0, 0, 0, 255);
	SDL_RenderPresent(GetRenderer());
	SDL_RenderClear(GetRenderer());
}

void CreateTexture(const char* texture_path, SDL_Texture** out_texture, Vec2& out_size)
{
	assert(texture_path != nullptr && "Texture path was not specified!");
	SDL_Surface* loaded_surface = IMG_Load(texture_path);
	assert(loaded_surface != nullptr && "Unable to load image");
	*out_texture = SDL_CreateTextureFromSurface(GetRenderer(), loaded_surface);
	assert(out_texture != nullptr && "Unable to create texture from surface!");
	out_size = { (float)loaded_surface->w, (float)loaded_surface->h };
	SDL_FreeSurface(loaded_surface);
}

void DrawObject(SDL_Texture* texture, Vec2 size, Vec2 pos)
{
	SDL_Rect dsrect = { pos.x, pos.y, size.x, size.y };
	assert(texture != nullptr && "Could not draw object, texture invalid!");
	SDL_RenderCopy(GetRenderer(), texture, NULL, &dsrect);
}

void DrawRect(SDL_Rect& size, SDL_Color&& color)
{
	SDL_SetRenderDrawColor(GetRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(GetRenderer(), &size);
}

void DrawGround()
{
	SDL_Rect ground = { 0, GROUND_LEVEL, SCREEN_WIDTH, SCREEN_HEIGHT - GROUND_LEVEL };
	DrawRect(ground, {90, 50, 35, 255});
}

void DrawFrog()
{

	SDL_Rect frogHead = { SCREEN_WIDTH / 2 + 150, SCREEN_HEIGHT / 2 - 50, 100, 50 };
	DrawRect(frogHead, { 100, 255, 50, 255 });

	SDL_Rect frog = { SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2, 200, 100 };
	DrawRect(frog, { 100, 255, 50, 255 });
}

void DrawMole()
{
	SDL_Rect moleHead = { SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2 - 50, 100, 50 };	
	DrawRect(moleHead, { 100, 100, 100, 255 });

	SDL_Rect mole = { SCREEN_WIDTH / 2 - 300, SCREEN_HEIGHT / 2, 200, 100 };
	DrawRect(mole, { 100, 100, 100, 255 });
}
