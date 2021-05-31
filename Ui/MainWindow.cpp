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

	this->setContentsMargins(0, 0, 5, 5);
	QGraphicsDropShadowEffect* wndShadow = new QGraphicsDropShadowEffect(this);
	wndShadow->setBlurRadius(5.0);
	wndShadow->setColor(QColor(0, 0, 0, 100));
	wndShadow->setOffset(2.0);
	this->setGraphicsEffect(wndShadow);

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

		QPoint current = event->globalPos();

		QPoint delta = current - this->prev;

		this->move(this->x() + delta.x(), this->y() + delta.y());

		this->prev = current;
	}
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event) {

	this->mousePressed = false;
}


#endif 