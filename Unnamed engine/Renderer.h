#pragma once
#include <GL/glew.h>
#include <SDL.h>
class Renderer
{
public:
	Renderer(SDL_Window *);
	~Renderer();
	void Render();

private:
	float c1 = 0.15435435f;
	float c2 = 0.5543543f;
	float c3 = 0.7543543f;
	float t = 0;
	SDL_Window *window;
};

