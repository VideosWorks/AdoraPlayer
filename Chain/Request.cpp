
#include "Request.h"

Request::Request(Request::RequestType requestType)
	:requestType(requestType) {

}

Request::~Request() {


}

/////////////////////////////////////////////////////////////////

RequestChangeWindowMode::RequestChangeWindowMode(CurrentWindowMode windowMode)
	:Request(Request::RequestType::RequestChangeWindowMode), windowMode(windowMode) {

}

RequestChangeWindowMode::~RequestChangeWindowMode() {


}
