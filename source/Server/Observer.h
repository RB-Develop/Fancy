#ifndef FANCY_OBSERVER
#define FANCY_OBSERVER

#include <set>
#include <NetworkData.h>

class Subject;

class Observer
{
public:
	virtual ~Observer() { };

	virtual void setInterest(unsigned int interest);
	virtual void addInterest(unsigned int interest);
	virtual void removeInterest(unsigned int interest);

	virtual void update(Subject* changedSubject) = 0;
protected:
	Observer() { };

	virtual bool isOfInterest(FancyPacket* packet);
private:
	std::set<unsigned int> _interests;
	unsigned int _interest;
};

#endif