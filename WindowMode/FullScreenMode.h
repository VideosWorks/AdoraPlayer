

#ifndef _FULLSCREENMODE_H
#define _FULLSCREENMODE_H

#include "WindowMode.h"

class FullScreenMode : public WindowMode {

public:
	FullScreenMode(MainWindow* mainWindow);
	~FullScreenMode();

	virtual void resizeEvent(QResizeEvent* event);

	virtual CurrentWindowMode getWindowMode() { return CurrentWindowMode::FullScreen; }

};

#endif //_FULLSCREENMODE_H