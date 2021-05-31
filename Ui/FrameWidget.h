
#ifndef _FRAMEWIDGET_H
#define _FRAMEWIDGET_H

#include <qwidget.h>
QT_BEGIN_NAMESPACE
namespace Ui { class FrameWidget; }
QT_END_NAMESPACE

class FrameWidget : public QWidget {

private:
	Ui::FrameWidget* ui;

public:
	FrameWidget(QWidget* parent = nullptr);
	~FrameWidget();

};

#endif //_FRAMEWIDGET_H