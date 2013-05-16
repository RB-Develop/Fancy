#ifndef FANCY_OBSERVER
#define FANCY_OBSERVER

class Subject;

class Observer
{
public:
	virtual ~Observer() { };
	virtual void update(Subject* changedSubject) = 0;
protected:
	Observer() { };
};

#endif