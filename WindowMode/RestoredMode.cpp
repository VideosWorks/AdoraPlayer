
#include "RestoredMode.h"
#include "../Ui/MainWindow.h"
#include <QMouseEvent>

RestoredMode::RestoredMode(MainWindow* mainWindow)
	:WindowMode(mainWindow), mousePressed(false), resizeBehavior(ResizeBehavior::Nothing) {

}

RestoredMode::~RestoredMode() {

}

void RestoredMode::resizeEvent(QResizeEvent* event) {


}

void RestoredMode::mousePressEvent(QMouseEvent* event) {

	this->mousePressed = true;
	this->prev = event->globalPos();
}

void RestoredMode::mouseMoveEvent(QMouseEvent* event) {

	if (this->mousePressed == true) {

		this->resize(this->prev, event->globalPos());
		this->prev = event->globalPos();
	}
	else {

		this->getResizeBehavior(event);
	}
}

void RestoredMode::mouseReleaseEvent(QMouseEvent* event) {

	this->mousePressed = false;
	this->mainWindow->setCursor(Qt::CursorShape::ArrowCursor);
}



void RestoredMode::getResizeBehavior(QMouseEvent* event) {

	int x = event->x();
	int y = event->y();
	
	QRect rect = this->mainWindow->rect();


	if (x >= rect.topLeft().x() + 10 && x <= rect.topRight().x() - 10 &&
		y >= rect.topLeft().y() - 5 && y <= rect.topLeft().y() + 10) {


		this->resizeBehavior = ResizeBehavior::ResizeTop;
		this->mainWindow->setCursor(QCursor(Qt::CursorShape::SizeVerCursor));
	}
	else if (x >= rect.topLeft().x() - 5 && x < rect.topLeft().x() + 5 &&
		y >= rect.topLeft().y() + 10 && y <= rect.bottomLeft().y() - 10) {

		this->resizeBehavior = ResizeBehavior::ResizeLeft;
		this->mainWindow->setCursor(QCursor(Qt::CursorShape::SizeHorCursor));
	}
	else if (x >= rect.topRight().x() - 5 && x <= rect.topRight().x() + 5 &&
		y >= rect.topLeft().y() + 10 && y <= rect.bottomLeft().y() - 10) {

		this->resizeBehavior = ResizeBehavior::ResizeRight;
		this->mainWindow->setCursor(QCursor(Qt::CursorShape::SizeHorCursor));
	}
	else if (x >= rect.topLeft().x() - 5 && x <= rect.topLeft().x() + 10 &&
		y >= rect.topLeft().y() - 5 && y <= rect.topLeft().y() + 10) {

		this->resizeBehavior = ResizeBehavior::ResizeTopLeft;
		this->mainWindow->setCursor(QCursor(Qt::CursorShape::SizeFDiagCursor));
	}
	else if (x >= rect.topRight().x() - 10 && x <= rect.topRight().x() + 10 &&
		y >= rect.topRight().y() - 5 && y <= rect.topRight().y() + 10) {

		this->resizeBehavior = ResizeBehavior::ResizeTopRight;
		this->mainWindow->setCursor(QCursor(Qt::CursorShape::SizeBDiagCursor));
	}
	else if (x >= rect.bottomLeft().x() + 10 && x <= rect.bottomRight().x() - 10 &&
		y >= rect.bottomLeft().y() - 5 && y <= rect.bottomLeft().y() + 10) {

		this->resizeBehavior = ResizeBehavior::ResizeBottom;
		this->mainWindow->setCursor(QCursor(Qt::CursorShape::SizeVerCursor));
	}
	else if (x >= rect.bottomLeft().x() - 5 && x <= rect.bottomLeft().x() + 10 &&
		y >= rect.bottomLeft().y() - 10 && y <= rect.bottomLeft().y() + 10) {

		this->resizeBehavior = ResizeBehavior::ResizeBottomLeft;
		this->mainWindow->setCursor(QCursor(Qt::CursorShape::SizeBDiagCursor));
	}
	else if (x >= rect.bottomRight().x() - 10 && x <= rect.bottomRight().x() + 10 &&
		y >= rect.bottomRight().y() - 10 && y <= rect.bottomRight().y() + 10) {

		this->resizeBehavior = ResizeBehavior::ResizeBottomRight;
		this->mainWindow->setCursor(QCursor(Qt::CursorShape::SizeFDiagCursor));
	}
	else {

		this->resizeBehavior = ResizeBehavior::Move;
		this->mainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
	}
}

void RestoredMode::resize(const QPoint& prev, const QPoint& current) {


	bool succeeded = false;

	QPoint delta = current - prev;
	QSize minumumSize = this->mainWindow->minimumSize();

	QRect rect = this->mainWindow->rect();

	if (resizeBehavior == ResizeBehavior::Move) {

		this->mainWindow->setGeometry(this->mainWindow->x() + delta.x(), this->mainWindow->y() + delta.y(),
			this->mainWindow->width(), this->mainWindow->height());

	}
	else if (resizeBehavior == ResizeBehavior::ResizeBottomRight) {

		this->mainWindow->setGeometry(this->mainWindow->x(), this->mainWindow->y(),
			this->mainWindow->width() + delta.x(), this->mainWindow->height() + delta.y());
	}
	else if (resizeBehavior == ResizeBehavior::ResizeTopRight) {

		if (this->mainWindow->width() + delta.x() <= minumumSize.width())
			return;

		if (this->mainWindow->height() - delta.y() <= minumumSize.height())
			return;

		this->mainWindow->setGeometry(this->mainWindow->x(), this->mainWindow->y() + delta.y(),
			this->mainWindow->width() + delta.x(), this->mainWindow->height() - delta.y());
	}
	else if (resizeBehavior == ResizeBehavior::ResizeTopLeft) {

		if (this->mainWindow->width() - delta.x() <= minumumSize.width())
			return;

		if (this->mainWindow->height() - delta.y() <= minumumSize.height())
			return;

		this->mainWindow->setGeometry(this->mainWindow->x() + delta.x(), this->mainWindow->y() + delta.y(),
			this->mainWindow->width() - delta.x(), this->mainWindow->height() - delta.y());

	}
	else if (resizeBehavior == ResizeBehavior::ResizeBottomLeft) {

		if (this->mainWindow->width() - delta.x() <= minumumSize.width())
			return;

		if (this->mainWindow->height() + delta.y() <= minumumSize.height())
			return;

		this->mainWindow->setGeometry(this->mainWindow->x() + delta.x(), this->mainWindow->y(),
			this->mainWindow->width() - delta.x(), this->mainWindow->height() + delta.y());

	}
	else if (resizeBehavior == ResizeBehavior::ResizeTop) {

		if (this->mainWindow->height() - delta.y() <= minumumSize.height())
			return;

		this->mainWindow->setGeometry(this->mainWindow->x(), this->mainWindow->y() + delta.y(),
			this->mainWindow->width(), this->mainWindow->height() - delta.y());

	}
	else if (resizeBehavior == ResizeBehavior::ResizeBottom) {

		if (this->mainWindow->height() + delta.y() <= minumumSize.height())
			return;

		this->mainWindow->setGeometry(this->mainWindow->x(), this->mainWindow->y(),
			this->mainWindow->width(), this->mainWindow->height() + delta.y());
	}
	else if (resizeBehavior == ResizeBehavior::ResizeLeft) {

		if (this->mainWindow->width() - delta.x() <= minumumSize.width())
			return;

		this->mainWindow->setGeometry(this->mainWindow->x() + delta.x(), this->mainWindow->y(),
			this->mainWindow->width() - delta.x(), this->mainWindow->height());

	}
	else if (resizeBehavior == ResizeBehavior::ResizeRight) {

		if (this->mainWindow->width() + delta.x() <= minumumSize.width())
			return;

		this->mainWindow->setGeometry(this->mainWindow->x(), this->mainWindow->y(),
			this->mainWindow->width() + delta.x(), this->mainWindow->height());

	}
}
