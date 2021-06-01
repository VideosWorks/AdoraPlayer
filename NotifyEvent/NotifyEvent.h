
#ifndef _NOTIFYEVENT_H
#define _NOTIFYEVENT_H

#include "../Base/Namespace.h"

class NotifyEvent {

public:
	enum class EventType {
		CurrentWindowModeChanged,

	};

protected:
	EventType eventType;

public:
	NotifyEvent(EventType eventType);
	virtual ~NotifyEvent() = 0;

public:
	inline EventType getEventType() const { return this->eventType; }
};

////////////////////////////////////////////////////////////

class CurrentWindowModeChangedEvent : public NotifyEvent {

private:
	CurrentWindowMode windowMode;

public:
	CurrentWindowModeChangedEvent(CurrentWindowMode windowMode);
	~CurrentWindowModeChangedEvent();

public:
	inline CurrentWindowMode getWindowMode() const { return this->windowMode; }
};

#endif //_NOTIFYEVENT_H
