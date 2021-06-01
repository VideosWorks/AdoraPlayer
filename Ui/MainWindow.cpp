#include "MainWindow.h"
#include "./ui_MainWindow.h"

#ifdef Q_OS_WIN
#include <QGraphicsDropShadowEffect>
#include "../WindowMode/WindowMode.h"
#include "../WindowMode/WindowModeFactory.h"
#endif

#include <qdebug.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

	

#ifdef Q_OS_WIN

	this->windowMode = nullptr;

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

	this->setContentsMargins(0, 0, 5, 5);
	QGraphicsDropShadowEffect* wndShadow = new QGraphicsDropShadowEffect(this);
	wndShadow->setBlurRadius(5.0);
	wndShadow->setColor(QColor(0, 0, 0, 100));
	wndShadow->setOffset(2.0);
	this->setGraphicsEffect(wndShadow);

	this->setWindowMode(CurrentWindowMode::Restored);
	
#endif 
	
#ifndef Q_OS_WIN

	ui->frameWidget->hide();
#endif

}

MainWindow::~MainWindow() {

#ifdef Q_OS_WIN

	if (this->windowMode != nullptr)
		delete this->windowMode;
#endif 

    delete ui;
}




#include <QMouseEvent>

void MainWindow::mousePressEvent(QMouseEvent* event) {
	
#ifdef Q_OS_WIN
	this->windowMode->mousePressEvent(event);
#endif

}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {

#ifdef Q_OS_WIN
	this->windowMode->mouseMoveEvent(event);
#endif 
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event) {

#ifdef Q_OS_WIN
	this->windowMode->mouseReleaseEvent(event);
#endif 
}

#ifdef Q_OS_WIN

void MainWindow::setWindowMode(CurrentWindowMode mode) {

	qDebug() << "setWindowMode";

	if (this->windowMode != nullptr)
		delete this->windowMode;

	this->windowMode = WindowModeFactory::create(this, mode);

}

#endif