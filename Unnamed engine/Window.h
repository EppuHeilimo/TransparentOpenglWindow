#pragma once
#include <SDL.h>
#include <SDL_syswm.h>
#include <GL/glew.h>
#include <iostream>

class Window
{
public:
	Window();
	~Window();
	SDL_Window *window;
	HWND handle;

};

