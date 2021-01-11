#include "MathDemoApp.h"
#include "MathLibrary.h"
#include <Windows.h>

using namespace MathLibrary;

// Returns a Vector2 of the screen size
Vector2 getScreenRes()
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();

	GetWindowRect(hDesktop, &desktop);

	return Vector2(desktop.right, desktop.bottom);
}

int main() {
	
	// sets screen resolution to size of screen
	Vector2 resoluton = getScreenRes();

	// allocation
	auto app = new MathDemoApp();

	// initialise and loop
	app->run("AIE", resoluton.x, resoluton.y, true);

	// deallocation
	delete app;

	return 0;
}