

#ifndef _FULLSCREENMODE_H
#define _FULLSCREENMODE_H

#include "WindowMode.h"

class FullScreenMode : public WindowMode {

public:
	FullScreenMode(MainWindow* mainWindow);
	~FullScreenMode();

	virtual void resizeEvent(QResizeEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);

	virtual CurrentWindowMode getWindowMode() { return CurrentWindowMode::FullScreen; }

};

#endif //_FULLSCREENMODE_H