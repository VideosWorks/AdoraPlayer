

#ifndef _WINDOWMODE_H
#define _WINDOWMODE_H

#include "../Base/Namespace.h"

class MainWindow;
class QResizeEvent;
class QMouseEvent;

class WindowMode {

protected:
	MainWindow* mainWindow;

public:
	WindowMode(MainWindow* mainWindow);
	virtual ~WindowMode() = 0;

	virtual void resizeEvent(QResizeEvent* event) = 0;
	virtual void mousePressEvent(QMouseEvent* event) = 0;
	virtual void mouseMoveEvent(QMouseEvent* event) = 0;
	virtual void mouseReleaseEvent(QMouseEvent* event) = 0;
	
	virtual CurrentWindowMode getWindowMode() = 0;
	
};

#endif //_WINDOWMODE_H