
#ifndef _FRAMEWIDGET_H
#define _FRAMEWIDGET_H

#include <qwidget.h>
QT_BEGIN_NAMESPACE
namespace Ui { class FrameWidget; }
QT_END_NAMESPACE

class FrameWidget : public QWidget {

	Q_OBJECT


private:
	Ui::FrameWidget* ui;

public:
	FrameWidget(QWidget* parent = nullptr);
	~FrameWidget();


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