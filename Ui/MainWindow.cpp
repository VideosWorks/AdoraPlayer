#include "MainWindow.h"
#include "./ui_MainWindow.h"

#ifdef Q_OS_WIN
#include <QGraphicsDropShadowEffect>
#endif

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

	

#ifdef Q_OS_WIN
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

	this->mousePressed = false;
	this->resizeBehavior = ResizeBehavior::Nothing;

	this->setContentsMargins(0, 0, 5, 5);
	QGraphicsDropShadowEffect* wndShadow = new QGraphicsDropShadowEffect(this);
	wndShadow->setBlurRadius(5.0);
	wndShadow->setColor(QColor(0, 0, 0, 100));
	wndShadow->setOffset(2.0);
	this->setGraphicsEffect(wndShadow);

	//this->showFullScreen();
	//this->setContentsMargins(0, 0, 0, 0);
	
#endif 
	
#ifndef Q_OS_WIN

	ui->frameWidget->hide();
#endif

}

MainWindow::~MainWindow() {

    delete ui;
}


#ifdef Q_OS_WIN

#include <qpainter.h>
#include <QMouseEvent>
void MainWindow::paintEvent(QPaintEvent* event) {

	QPainter painter(this);
	/*
	painter.setRenderHint(QPainter::Antialiasing); // Anti-aliasing;
	painter.setBrush(QBrush(QColor("#424242")));
	painter.setPen(Qt::transparent);
	QRect rect(this->rect());
	rect.setWidth(rect.width());
	rect.setHeight(rect.height());
	painter.drawRoundedRect(rect, 14, 14);
	*/
	
}

void MainWindow::mousePressEvent(QMouseEvent* event) {

	this->mousePressed = true;
	this->prev = event->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {

	if (this->mousePressed == true) {

		this->resize(this->prev, event->globalPos());
		this->prev = event->globalPos();
	}
	else {
	
		this->getResizeBehavior(event);
	}
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event) {

	this->mousePressed = false;
	this->setCursor(Qt::CursorShape::ArrowCursor);
}

void MainWindow::getResizeBehavior(QMouseEvent* event) {

	int x = event->x();
	int y = event->y();

	QRect rect = this->rect();


	if (x >= rect.topLeft().x() + 10 && x <= rect.topRight().x() - 10 &&
		y >= rect.topLeft().y() - 5 && y <= rect.topLeft().y() + 10) {


		this->resizeBehavior = ResizeBehavior::ResizeTop;
		this->setCursor(QCursor(Qt::CursorShape::SizeVerCursor));
	}
	else if (x >= rect.topLeft().x() - 5 && x < rect.topLeft().x() + 5 &&
		y >= rect.topLeft().y() + 10 && y <= rect.bottomLeft().y() - 10) {

		this->resizeBehavior = ResizeBehavior::ResizeLeft;
		this->setCursor(QCursor(Qt::CursorShape::SizeHorCursor));
	}
	else if (x >= rect.topRight().x() - 5 && x <= rect.topRight().x() + 5 &&
		y >= rect.topLeft().y() + 10 && y <= rect.bottomLeft().y() - 10) {

		this->resizeBehavior = ResizeBehavior::ResizeRight;
		this->setCursor(QCursor(Qt::CursorShape::SizeHorCursor));
	}
	else if (x >= rect.topLeft().x() - 5 && x <= rect.topLeft().x() + 10 &&
		y >= rect.topLeft().y() - 5 && y <= rect.topLeft().y() + 10) {

		this->resizeBehavior = ResizeBehavior::ResizeTopLeft;
		this->setCursor(QCursor(Qt::CursorShape::SizeFDiagCursor));
	}
	else if (x >= rect.topRight().x() - 10 && x <= rect.topRight().x() + 10 &&
		y >= rect.topRight().y() - 5 && y <= rect.topRight().y() + 10) {

		this->resizeBehavior = ResizeBehavior::ResizeTopRight;
		this->setCursor(QCursor(Qt::CursorShape::SizeBDiagCursor));
	}
	else if (x >= rect.bottomLeft().x() + 10 && x <= rect.bottomRight().x() - 10 &&
		y >= rect.bottomLeft().y() - 5 && y <= rect.bottomLeft().y() + 10) {

		this->resizeBehavior = ResizeBehavior::ResizeBottom;
		this->setCursor(QCursor(Qt::CursorShape::SizeVerCursor));
	}
	else if (x >= rect.bottomLeft().x() - 5 && x <= rect.bottomLeft().x() + 10 &&
		y >= rect.bottomLeft().y() - 10 && y <= rect.bottomLeft().y() + 10) {

		this->resizeBehavior = ResizeBehavior::ResizeBottomLeft;
		this->setCursor(QCursor(Qt::CursorShape::SizeBDiagCursor));
	}
	else if (x >= rect.bottomRight().x() - 10 && x <= rect.bottomRight().x() + 10 &&
		y >= rect.bottomRight().y() - 10 && y <= rect.bottomRight().y() + 10) {

		this->resizeBehavior = ResizeBehavior::ResizeBottomRight;
		this->setCursor(QCursor(Qt::CursorShape::SizeFDiagCursor));
	}
	else {

		this->resizeBehavior = ResizeBehavior::Move;
		this->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
	}
}

void MainWindow::resize(const QPoint& prev, const QPoint& current) {


	bool succeeded = false;

	QPoint delta = current - prev;
	QSize minumumSize = this->minimumSize();

	QRect rect = this->rect();

	if (resizeBehavior == ResizeBehavior::Move) {

		this->setGeometry(this->x() + delta.x(), this->y() + delta.y(),
			this->width(), this->height());

	}
	else if (resizeBehavior == ResizeBehavior::ResizeBottomRight) {

		this->setGeometry(this->x(), this->y(),
			this->width() + delta.x(), this->height() + delta.y());
	}
	else if (resizeBehavior == ResizeBehavior::ResizeTopRight) {

		if (this->width() + delta.x() <= minumumSize.width())
			return;

		if (this->height() - delta.y() <= minumumSize.height())
			return;

		this->setGeometry(this->x(), this->y() + delta.y(),
			this->width() + delta.x(), this->height() - delta.y());
	}
	else if (resizeBehavior == ResizeBehavior::ResizeTopLeft) {

		if (this->width() - delta.x() <= minumumSize.width())
			return;

		if (this->height() - delta.y() <= minumumSize.height())
			return;

		this->setGeometry(this->x() + delta.x(), this->y() + delta.y(),
			this->width() - delta.x(), this->height() - delta.y());

	}
	else if (resizeBehavior == ResizeBehavior::ResizeBottomLeft) {

		if (this->width() - delta.x() <= minumumSize.width())
			return;

		if (this->height() + delta.y() <= minumumSize.height())
			return;

		this->setGeometry(this->x() + delta.x(), this->y(),
			this->width() - delta.x(), this->height() + delta.y());

	}
	else if (resizeBehavior == ResizeBehavior::ResizeTop) {

		if (this->height() - delta.y() <= minumumSize.height())
			return;

		this->setGeometry(this->x(), this->y() + delta.y(),
			this->width(), this->height() - delta.y());

	}
	else if (resizeBehavior == ResizeBehavior::ResizeBottom) {

		if (this->height() + delta.y() <= minumumSize.height())
			return;

		this->setGeometry(this->x(), this->y(),
			this->width(), this->height() + delta.y());
	}
	else if (resizeBehavior == ResizeBehavior::ResizeLeft) {

		if (this->width() - delta.x() <= minumumSize.width())
			return;

		this->setGeometry(this->x() + delta.x(), this->y(),
			this->width() - delta.x(), this->height());

	}
	else if (resizeBehavior == ResizeBehavior::ResizeRight) {

		if (this->width() + delta.x() <= minumumSize.width())
			return;

		this->setGeometry(this->x(), this->y(),
			this->width() + delta.x(), this->height());

	}
}

#endif 