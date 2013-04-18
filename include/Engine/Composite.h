#ifndef COMPOSITE
#define COMPOSITE

#include "Component.h"
#include <list>

class Composite : public Component
{
public:
	virtual ~Composite()
	{
		while(!components.empty()) delete components.front(), components.pop_front();
	}

	virtual void update()
	{
		for (std::list<Component*>::iterator i = components.begin(); i != components.end(); ++i)
		{
			(*i)->update();
		}
	}

	virtual void handleMessage(unsigned int message, void* data)
	{
		std::list<Component*>::iterator i;
		for (i = components.begin(); i != components.end(); ++i)
		{
			(*i)->handleMessage(message, data);
		}
		delete *i;
	}

	virtual void addComponent(Component* component) 
	{
		components.push_back(component);
	}
	virtual void removeComponent(Component* component)
	{
		components.remove(component);
	}
protected:
	Composite(const char* name) : Component(name) {};
private:
	std::list<Component*> components;
};

#endif