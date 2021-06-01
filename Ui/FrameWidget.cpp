
#include "FrameWidget.h"
#include <./ui_FrameWidget.h>
#include <qpainter.h>

FrameWidget::FrameWidget(QWidget* parent)
	:QWidget(parent),ui(new Ui::FrameWidget) {

	ui->setupUi(this);


	ui->restoreButton->hide();
	ui->neverPinButton->hide();
	ui->onlyPlayPinButton->hide();


	connect(ui->closeButton, &QPushButton::clicked, this, &FrameWidget::closeButtonClicked);
	connect(ui->maximizeButton, &QPushButton::clicked, this, &FrameWidget::maximizeButtonClicked);
	connect(ui->minimizeButton, &QPushButton::clicked, this, &FrameWidget::minimizeButtonClicked);
	connect(ui->restoreButton, &QPushButton::clicked, this, &FrameWidget::restoreButtonClicked);
	connect(ui->alwaysPinButton, &QPushButton::clicked, this, &FrameWidget::alwaysPinButtonClicked);
	connect(ui->fullscreenButton, &QPushButton::clicked, this, &FrameWidget::fullscreenButtonClicked);
	connect(ui->onlyPlayPinButton, &QPushButton::clicked, this, &FrameWidget::onlyPlayPinButtonClicked);
	connect(ui->neverPinButton, &QPushButton::clicked, this, &FrameWidget::neverPinButtonClicked);
	connect(ui->settingsButton, &QPushButton::clicked, this, &FrameWidget::settingsButtonClicked);


}

FrameWidget::~FrameWidget() {

	delete ui;
}

void FrameWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);

	painter.fillRect(this->rect(), QColor("#FFC23D"));
}


void FrameWidget::closeButtonClicked() {

}

void FrameWidget::maximizeButtonClicked() {

}

void FrameWidget::minimizeButtonClicked() {

}

void FrameWidget::restoreButtonClicked() {

}

void FrameWidget::alwaysPinButtonClicked() {

}

void FrameWidget::onlyPlayPinButtonClicked() {

}

void FrameWidget::neverPinButtonClicked() {

}

void FrameWidget::settingsButtonClicked() {

}

void FrameWidget::fullscreenButtonClicked() {

}
