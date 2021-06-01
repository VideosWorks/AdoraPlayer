

#ifndef _RESTOREDMODE_H
#define _RESTOREDMODE_H

#include "WindowMode.h"

class RestoredMode : public WindowMode {


public:
	RestoredMode(MainWindow* mainWindow);
	~RestoredMode();

	virtual void resizeEvent(QResizeEvent* event);

	virtual CurrentWindowMode getWindowMode() { return CurrentWindowMode::Restored; }

};

#endif //_RESTOREDMODE_H