#ifndef FANCY_BASE_COMP
#define FANCY_BASE_COMP
#include <Irrlicht/irrlicht.h>

class Component
{
public:
	virtual ~Component() {};

	const char* getName() { return _name; }

	virtual void init() {};
	virtual void update() {};
	virtual void handleMessage(unsigned int, void* data = 0) { };
	virtual void cleanUp() {};
protected:
	Component(const char*) {};
private:
	const char* _name;
};


#endif

