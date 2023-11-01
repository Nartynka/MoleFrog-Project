#pragma once
#include "../Vec2.h"

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

struct SDL_Rect;
struct SDL_Texture;

void RenderInit(); 
void RenderTerminate();

void Render();

void DrawObject(SDL_Texture* texture, Vec2 size, Vec2 pos);
void CreateTexture(const char* texture_path, SDL_Texture** out_texture, Vec2& out_size);

void DrawRect(SDL_Rect& size, struct SDL_Color&& color);
void DrawMole();
void DrawFrog();
