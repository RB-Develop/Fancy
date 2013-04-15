#include <Engine\Scene.h>

Scene::Scene() : Composite(NULL)
{
	// Set the state
	state = LOADING;

	// Scene is enabled
	//enabled = true;
}

Scene::~Scene()
{
	Composite::~Composite();
}
