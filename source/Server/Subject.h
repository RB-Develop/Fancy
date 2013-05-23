#ifndef FANCY_SUBJECT
#define FANCY_SUBJECT

#include "Observer.h"

#include <list>

class Subject
{
public:
	virtual ~Subject() { };

	virtual void attach(Observer*);
	virtual void detach(Observer*);

	/*
	* Notifies all the registered Observer objects in the
	* observers list.
	*/
	virtual void notify(FancyPacket) = 0;
protected:
	Subject() { };
private:
	std::list<Observer*> _observers;
};

#endif