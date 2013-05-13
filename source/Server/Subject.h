#ifndef FANCY_SUBJECT
#define FANCY_SUBJECT

#include "Observer.h"
#include <list>

class Subject
{
public:
	virtual ~Subject();

	virtual void attach(Observer*);
	virtual void detach(Observer*);
	virtual void notify();
protected:
	Subject();
private:
	std::list<Observer*> *_observers;
};

void Subject::attach(Observer* o)
{
	_observers->push_back(o);
}

void Subject::detach(Observer* o)
{
	_observers->remove(o);
}

void Subject::notify()
{
	std::list<Observer*>::iterator iter;

	for(iter = _observers->begin(); iter != _observers->end(); iter++)
	{
		(*iter)->update(*this);
	}
}

#endif