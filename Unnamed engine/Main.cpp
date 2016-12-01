#include <iostream>
#include <SDL.h>
#include <SDL_syswm.h>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <dwmapi.h>
#include <cassert>
#include <cmath>
#pragma comment(lib, "glew32.lib")

int main(int argc, char ** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

	SDL_Window *window;
	window = SDL_CreateWindow("asd",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		1680, 1024, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(window);


	GLenum status = glewInit();
	if (status != GLEW_OK) {
		std::cerr << "Glew failed to initialize!\n";
	}
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFuncSeparate(GL_ONE, GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);
	bool closed = false;
	SDL_Event e;

	SDL_SysWMinfo sysinfo;
	SDL_VERSION(&sysinfo.version);
	SDL_GetWindowWMInfo(window, &sysinfo);
	HWND handle = sysinfo.info.win.window;
	int asd = 0;


	//Remove all cluster from window (title bar and borders)
	SetWindowLong(handle, GWL_STYLE, ::GetWindowLong(handle, GWL_STYLE) & ~(WS_BORDER | WS_DLGFRAME | WS_THICKFRAME));
	SetWindowLong(handle, GWL_EXSTYLE, ::GetWindowLong(handle, GWL_EXSTYLE) & ~WS_EX_DLGMODALFRAME);
	SetWindowLong(handle, GWL_STYLE, GetWindowLong(handle, GWL_STYLE) | WS_POPUP &~WS_OVERLAPPEDWINDOW);
	//SetWindowLong(handle, GWL_EXSTYLE, GetWindowLong(handle, GWL_EXSTYLE) | WS_EX_LAYERED);
	

	//updatelayeredwindow <<--- CHECK OUT http://stackoverflow.com/questions/18383681/setlayeredwindowattributes-to-make-a-window-transparent-is-only-working-part-of
	//CHECK OUT http://www.nuonsoft.com/blog/2009/05/27/how-to-use-updatelayeredwindow/
	float c1 = 0.15435435f;
	float c2 = 0.5543543f;
	float c3 = 0.7543543f;
	float t = 0;
	DWM_BLURBEHIND bb = { 0 };
	bb.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;;
	bb.fEnable = true;
	bb.hRgnBlur = CreateRectRgn(0, 0, -1, -1);
	HRESULT qwe;
	glMatrixMode(GL_PROJECTION);
	qwe = DwmEnableBlurBehindWindow(handle, &bb);
	if (SUCCEEDED(qwe))
	{
		while (!closed)
		{
			
			t+=0.01f;
			while (SDL_PollEvent(&e)) {
				switch (e.type) {
				case SDL_QUIT:
					closed = true;
				}
			}
			
			glLoadIdentity();
			glClearColor(0, 0, 0, 0);
			//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glRotatef(t * 5, 0, 0, 1);
			glBegin(GL_TRIANGLE_STRIP);

			for (int i = 0; i < 10; i++)
			{
				float shit = sin(i * i * sqrtf(float(i))) / 200;				                           // Drawing Using Triangles
				glColor4f(abs(sin(c1 * t)), abs(sin(c2 * t)), abs(sin(c3 * t)), shit);                      // Set The Color To Red
				glVertex3f(sin(c1 * t) * shit * shit, sin(c2 * t * shit), 0.0f);						// Top
				glColor4f(abs(sin(c2 * t)), abs(sin(c3 * t)), abs(sin(c1 * t)), sin(shit));                      // Set The Color To Green
				glVertex3f(sin(c3 * t * shit + shit), sin(c1 * t * shit + shit), 0.0f);                  // Bottom Left
				glColor4f(abs(sin(c3 * t)), abs(sin(c1 * t)), abs(sin(c2 * t)), cos(shit * sin(shit)));                      // Set The Color To Blue
				glVertex3f(sin(c2 * t * shit), sin(c3 * t / shit), 0.0f);                  // Bottom Right
				
			}
			glEnd();
			SDL_GL_SwapWindow(window);
			
		}
	}
	SDL_GL_DeleteContext(window);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
