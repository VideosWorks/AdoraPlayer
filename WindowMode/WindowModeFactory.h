
#ifndef _WINDOWMODEFACTORY_H
#define _WINDOWMODEFACTORY_H

#include "../Base/Namespace.h"

class MainWindow;
class WindowMode;


class WindowModeFactory {

public:
	WindowModeFactory();
	~WindowModeFactory();

	static WindowMode* create(MainWindow* mainWindow, CurrentWindowMode mode);

};

#endif //_WINDOWMODEFACTORY_H