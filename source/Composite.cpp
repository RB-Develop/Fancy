#include <Engine\Composite.h>

Composite::Composite(const char* name):Component(name)
{
}


Composite::~Composite()
{
	for (std::list<Component*>::iterator i = components.begin(); i != components.end(); ++i)
	{
		delete (*i);
	}
	components.clear();
}

void Composite::handleMessage(unsigned int message, void* data)
{
	std::list<Component*>::iterator i;
	for (i = components.begin(); i != components.end(); ++i)
	{
		(*i)->handleMessage(message, data);
	}
	delete *i;
}

void Composite::update()
{
	for (std::list<Component*>::iterator i = components.begin(); i != components.end(); ++i)
	{
		(*i)->update();
	}
}

void Composite::addComponent(Component* component)
{
	components.push_back(component);
}

void Composite::removeComponent(Component* component)
{
	components.remove(component);
	delete component;
}

