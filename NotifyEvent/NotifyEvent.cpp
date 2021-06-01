

#include "NotifyEvent.h"

NotifyEvent::NotifyEvent(EventType eventType)
	:eventType(eventType) {

}

NotifyEvent::~NotifyEvent() {


}

/////////////////////////////////////////////////////////////

CurrentWindowModeChangedEvent::CurrentWindowModeChangedEvent(CurrentWindowMode windowMode)
	:NotifyEvent(EventType::CurrentWindowModeChanged), windowMode(windowMode) {

}

CurrentWindowModeChangedEvent::~CurrentWindowModeChangedEvent() {

}