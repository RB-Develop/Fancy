#ifndef FANCY_SCENE
#define FANCY_SCENE

#include <Engine/Composite.h>

class Scene : public Composite
{
public:
	virtual void update() = 0;
	virtual void handleMessage(unsigned int) {};
	virtual void addComponent(Component*);
	virtual void removeComponent(Component*);
protected:
	Scene(const char*);
};

#endif