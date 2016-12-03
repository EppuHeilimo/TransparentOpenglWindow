#include "Renderer.h"
#include "Window.h"


Renderer::Renderer(SDL_Window *window)
{
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFuncSeparate(GL_ONE, GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);
	glMatrixMode(GL_PROJECTION);
	this->window = window;
}


Renderer::~Renderer()
{
}

void Renderer::Render()
{
	t += 0.01f;
	glLoadIdentity();
	glClearColor(0, 0, 0, 0);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(t * 5, 0, 0, 1);
	glBegin(GL_TRIANGLE_STRIP);

	for (int i = 0; i < 10; i++)
	{
		float shit = sin(i * i * sqrtf(float(i))) / 200;				  
		glColor4f(abs(sin(c1 * t)), abs(sin(c2 * t)), abs(sin(c3 * t)), shit);                    
		glVertex3f(sin(c1 * t) * shit * shit, sin(c2 * t * shit), 0.0f);						// Top
		glColor4f(abs(sin(c2 * t)), abs(sin(c3 * t)), abs(sin(c1 * t)), sin(shit));                
		glVertex3f(sin(c3 * t * shit + shit), sin(c1 * t * shit + shit), 0.0f);                  // Bottom Left
		glColor4f(abs(sin(c3 * t)), abs(sin(c1 * t)), abs(sin(c2 * t)), cos(shit * sin(shit)));      
		glVertex3f(sin(c2 * t * shit), sin(c3 * t / shit), 0.0f);                  // Bottom Right
	}
	glEnd();
	SDL_GL_SwapWindow(window);
}

