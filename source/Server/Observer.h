#ifndef FANCY_OBSERVER
#define FANCY_OBSERVER

#include <set>
#include <NetworkData.h>

class Subject;

class Observer
{
public:
	virtual ~Observer() { };

	virtual void update(FancyPacket) = 0;
protected:
	Observer() { };
};

#endif