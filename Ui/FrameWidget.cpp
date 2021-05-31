
#include "FrameWidget.h"
#include <./ui_FrameWidget.h>

FrameWidget::FrameWidget(QWidget* parent)
	:QWidget(parent),ui(new Ui::FrameWidget) {

	ui->setupUi(this);
}

FrameWidget::~FrameWidget() {

	delete ui;
}
