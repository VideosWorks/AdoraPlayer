
#include "WindowModeFactory.h"
#include "FullScreenMode.h"
#include "MaximizedMode.h"
#include "RestoredMode.h"

WindowModeFactory::WindowModeFactory() {

}

WindowModeFactory::~WindowModeFactory() {

}

WindowMode* WindowModeFactory::create(MainWindow* mainWindow, CurrentWindowMode mode) {

	WindowMode* windowMode = nullptr;

	if (mode == CurrentWindowMode::FullScreen)
		windowMode = new FullScreenMode(mainWindow);

	else if (mode == CurrentWindowMode::Maximized)
		windowMode = new MaximizedMode(mainWindow);

	else if (mode == CurrentWindowMode::Restored)
		windowMode == new RestoredMode(mainWindow);



	return windowMode;
}

