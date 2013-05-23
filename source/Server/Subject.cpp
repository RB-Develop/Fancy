#include "Subject.h"

void Subject::attach(Observer* o)
{
	_observers.push_back(o);
}

void Subject::detach(Observer* o)
{
	_observers.remove(o);
}

void Subject::notify(FancyPacket packet)
{
	std::list<Observer*>::iterator iter;

	for(iter = _observers.begin(); iter != _observers.end(); iter++)
	{
		(*iter)->update(packet);
	}
}
