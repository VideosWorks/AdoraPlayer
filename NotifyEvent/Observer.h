
#ifndef _OBSERVER_H
#define _OBSERVER_H

class NotifyEvent;

class Observer {

public:
	Observer();
	virtual ~Observer() = 0;

	virtual void updateNotifyEvent(NotifyEvent *event) {}

};

#endif //_OBSERVER_H