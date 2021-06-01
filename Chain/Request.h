
#ifndef _REQUEST_H
#define _REQUEST_H

#include "../Base/Namespace.h"

class Request {

public:
	enum class RequestType {
		RequestChangeWindowMode,
		
	};

protected:
	RequestType requestType;

public:
	Request(RequestType requestType);
	virtual ~Request() = 0;

	inline RequestType getRequestType() const { return this->requestType; }
};

////////////////////////////////////////////////////////////

class RequestChangeWindowMode : public Request {

private:
	CurrentWindowMode windowMode;

public:
	RequestChangeWindowMode(CurrentWindowMode windowMode);
	~RequestChangeWindowMode();

public:
	inline CurrentWindowMode getWindowMode() const { return this->windowMode; }
};

#endif //_REQUEST_H