#pragma once
#include <SDL_syswm.h>
#include <dwmapi.h>

static class NoWindow
{
public:
	static void HideWindowTrash(HWND handle);
	static bool MakeBackgroundTransparent(HWND handle);
	static void ToggleWindowClickThrough(HWND handle);
	static void MakeAlwaysOnTop(HWND handle);
};

