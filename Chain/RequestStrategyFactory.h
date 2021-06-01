
#ifndef _REQUESTSTRATEGYFACTORY_H
#define _REQUESTSTRATEGYFACTORY_H

class MainWindow;
class Request;
class RequestStrategy;


class RequestStrategyFactory {

public:
	RequestStrategyFactory();
	~RequestStrategyFactory();

	static RequestStrategy* create(MainWindow* mainWindow, Request* request);

};

#endif //_REQUESTSTRATEGYFACTORY_H