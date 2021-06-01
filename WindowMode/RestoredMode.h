

#ifndef _RESTOREDMODE_H
#define _RESTOREDMODE_H

#include "WindowMode.h"
#include <qpoint.h>
#include "../Base/Namespace.h"

class RestoredMode : public WindowMode {

private:
	bool mousePressed;
	QPoint prev;
	ResizeBehavior resizeBehavior;

public:
	RestoredMode(MainWindow* mainWindow);
	~RestoredMode();

	virtual void resizeEvent(QResizeEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);

	virtual CurrentWindowMode getWindowMode() { return CurrentWindowMode::Restored; }


private:
	void getResizeBehavior(QMouseEvent* event);
	void resize(const QPoint& prev, const QPoint& current);
};

#endif //_RESTOREDMODE_H