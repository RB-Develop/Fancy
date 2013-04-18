#include <Engine\Scene.h>

Scene::Scene(const char* name) : Composite(name)
{
}

void Scene::update()
{
	Composite::update();
}

void Scene::addComponent(Component* component)
{
	Composite::addComponent(component);
}

void Scene::removeComponent(Component* component)
{
	Composite::removeComponent(component);
}