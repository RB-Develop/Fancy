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
	virtual void notify();
protected:
	Subject() { };
private:
	std::list<Observer*> _observers;
};

#endif