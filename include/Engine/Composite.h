#ifndef COMPOSITE
#define COMPOSITE

#include "Component.h"
#include <list>

class Composite : public Component
{
public:
	virtual ~Composite();

	virtual void update();
	virtual void handleMessage(unsigned int message, void* data);

	virtual void addComponent(Component* component);
	virtual void removeComponent(Component* component);
protected:
	Composite(const char*);
private:
	std::list<Component*> components;
};

#endif