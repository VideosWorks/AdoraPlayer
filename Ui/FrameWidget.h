
#ifndef _FRAMEWIDGET_H
#define _FRAMEWIDGET_H

#include <qwidget.h>
QT_BEGIN_NAMESPACE
namespace Ui { class FrameWidget; }
QT_END_NAMESPACE


#include "../Chain/Chain.h"
#include "../NotifyEvent/Observer.h"


class FrameWidget : public QWidget, public Chain, public Observer {

	Q_OBJECT

private:
	Ui::FrameWidget* ui;

public:
	FrameWidget(QWidget* parent = nullptr);
	~FrameWidget();

	virtual void updateNotifyEvent(NotifyEvent* event);

protected:
	virtual void paintEvent(QPaintEvent* event);


private slots:
	void closeButtonClicked();
	void maximizeButtonClicked();
	void minimizeButtonClicked();
	void restoreButtonClicked();
	void alwaysPinButtonClicked();
	void onlyPlayPinButtonClicked();
	void neverPinButtonClicked();
	void settingsButtonClicked();
	void fullscreenButtonClicked();

};

#endif //_FRAMEWIDGET_H