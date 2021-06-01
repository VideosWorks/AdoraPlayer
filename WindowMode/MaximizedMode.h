
#ifndef _MAXIMIZEDMODE_H
#define _MAXIMIZEDMODE_H

#include "WindowMode.h"

class MaximizedMode : public WindowMode {

public:
	MaximizedMode(MainWindow* mainWindow);
	~MaximizedMode();

	virtual void resizeEvent(QResizeEvent* event);

	virtual CurrentWindowMode getWindowMode() { return CurrentWindowMode::Maximized; }


};

#endif //_MAXIMIZEDMODE_H