

#include "RequestStrategy.h"
#include "Request.h"
#include "../Ui/MainWindow.h"


RequestStrategy::RequestStrategy(MainWindow* mainWindow, Request* request)
	:mainWindow(mainWindow), request(request) {

}

RequestStrategy::~RequestStrategy() {


}

////////////////////////////////////////////////////////


RequestChangeWindowModeStrategy::RequestChangeWindowModeStrategy(MainWindow* mainWindow, Request* request)
	:RequestStrategy(mainWindow, request) {

}

RequestChangeWindowModeStrategy::~RequestChangeWindowModeStrategy() {

}

#include <qmessagebox.h>
bool RequestChangeWindowModeStrategy::response() {

	QMessageBox box;
	box.exec();
	return true;
}