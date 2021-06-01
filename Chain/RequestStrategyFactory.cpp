
#include "RequestStrategyFactory.h"
#include "Request.h"
#include "RequestStrategy.h"

RequestStrategyFactory::RequestStrategyFactory() {

}

RequestStrategyFactory::~RequestStrategyFactory() {

}

RequestStrategy* RequestStrategyFactory::create(MainWindow* mainWindow, Request* request) {

	RequestStrategy* strategy = nullptr;

	if (request->getRequestType() == Request::RequestType::RequestChangeWindowMode) {
	
		strategy = new RequestChangeWindowModeStrategy(mainWindow, request);
	}
	

	return strategy;
}