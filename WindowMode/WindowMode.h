

#ifndef _WINDOWMODE_H
#define _WINDOWMODE_H

#include "../Base/Namespace.h"

class MainWindow;
class QResizeEvent;

class WindowMode {

protected:
	MainWindow* mainWindow;

public:
	WindowMode(MainWindow* mainWindow);
	virtual ~WindowMode() = 0;

	virtual void resizeEvent(QResizeEvent* event) = 0;
	
	virtual CurrentWindowMode getWindowMode() = 0;
	
};

#endif //_WINDOWMODE_H