#pragma once
#include <GL/glew.h>
#include <SDL.h>
#include <glm\glm.hpp>
#include "Settings.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Math.cpp"
#include "PrimitiveShaderProgram.h"
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
	glm::mat4 projectionMatrix;
	SDL_Window *window;
	PrimitiveShaderProgram *shader;
};

