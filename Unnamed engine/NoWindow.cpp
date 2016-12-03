#include "NoWindow.h"

void NoWindow::HideWindowTrash(HWND handle)
{
	//Remove all cluster from window (title bar and borders)
	SetWindowLong(handle, GWL_STYLE, ::GetWindowLong(handle, GWL_STYLE) & ~(WS_BORDER | WS_DLGFRAME | WS_THICKFRAME));
	SetWindowLong(handle, GWL_EXSTYLE, ::GetWindowLong(handle, GWL_EXSTYLE) & ~WS_EX_DLGMODALFRAME);
	SetWindowLong(handle, GWL_STYLE, GetWindowLong(handle, GWL_STYLE) | WS_POPUP & ~WS_OVERLAPPEDWINDOW);
	SetWindowLong(handle, GWL_EXSTYLE, GetWindowLong(handle, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(handle, RGB(255, 0, 0), 0, LWA_COLORKEY);

}

bool NoWindow::MakeBackgroundTransparent(HWND handle)
{
	DWM_BLURBEHIND bb = {0};
	bb.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;;
	bb.fEnable = true;
	bb.hRgnBlur = CreateRectRgn(0, 0, -1, -1);
	HRESULT qwe;
	qwe = DwmEnableBlurBehindWindow(handle, &bb);
	if (SUCCEEDED(qwe))
	{
		return true;
	}
	return false;
}

void NoWindow::ToggleWindowClickThrough(HWND handle)
{
	SetWindowLong(handle, GWL_EXSTYLE, GetWindowLong(handle, GWL_EXSTYLE) ^ WS_EX_TRANSPARENT);
}

void NoWindow::MakeAlwaysOnTop(HWND handle)
{
	SetWindowPos(handle, HWND_TOPMOST, -1, -1, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 0);
}

