#include <iostream>
#include <cassert>
#include <cmath>
#include "Window.h"
#include "Renderer.h"
#include "Settings.h"

#pragma comment(lib, "glew32.lib")

int main(int argc, char ** argv)
{
	FOV = 60.0f;
	Window *window = new Window();
	Renderer *renderer = new Renderer(window->window);
	bool closed = false;
	SDL_Event e;
	while (!closed)
	{
		renderer->Render();
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				closed = true;
			}
		}	
	}
	delete window;
	delete renderer;

	return 0;
}
