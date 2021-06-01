
#ifndef _REQUESTSTRATEGY_H
#define _REQUESTSTRATEGY_H

class MainWindow;
class Request;

class RequestStrategy {


protected:
	MainWindow* mainWindow;
	Request* request;

public:
	RequestStrategy(MainWindow* mainWindow, Request* request);
	virtual ~RequestStrategy() = 0;

	virtual bool response() = 0;
};

/////////////////////////////////////////////////////////

class RequestChangeWindowModeStrategy : public RequestStrategy {

public:
	RequestChangeWindowModeStrategy(MainWindow* mainWindow, Request* request);
	~RequestChangeWindowModeStrategy();

	virtual bool response();

};
#endif //_REQUESTSTRATEGY_H