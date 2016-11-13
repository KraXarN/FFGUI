#include <ui.h>

// Windows only
#include <Windows.h>

// C++ includes
#include <string>
#include <iostream>

// Namespace
using namespace std;

// libui
uiWindow *mainWindow;

// Vars

// UI Elements

// Functions
static int onClosing(uiWindow *w, void *data);

int main(int argc, char *argv[])
{
	// Init libui
	uiInitOptions initOptions;
	memset(&initOptions, 0, sizeof(uiInitOptions));
	uiInit(&initOptions);

	// Main window
	mainWindow = uiNewWindow("FFGUI - GUI for FFmpeg", 848, 480, false);
	uiWindowSetMargined(mainWindow, 1);
	uiWindowOnClosing(mainWindow, onClosing, NULL);

	// Show UI
	uiControlShow(uiControl(mainWindow));
	uiMain();

	return 0;
}

static int onClosing(uiWindow *w, void *data)
{
	uiControlDestroy(uiControl(mainWindow));
	uiUninit();
	uiQuit();
	return 0;
}