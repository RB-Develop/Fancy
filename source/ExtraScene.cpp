#include <Engine/Scene.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/CameraComponent.h>
#include <Engine/Core.h>
#include <Engine/Skybox.h>

using namespace fancy;
using namespace fancy::scene;
using namespace fancy::object;

class ExtraScene : public Scene
{
private:
	Core* _core;
public:
	ExtraScene(Core* core) : Scene("ExtraMenu")
	{
		addComponent(new CameraComponent(core->getSmgr(), CameraComponent::FIRST_PERSON));
		addComponent(new PrimitiveComponent(core->getSmgr(), PrimitiveComponent::PRIM_SPHERE, 2));
		addComponent(new Skybox(core->getSmgr(), core->getDriver(), "sky")); 
		_core = core;
	}

	~ExtraScene()
	{
		_core = NULL;
	}

	void update()
	{
		//TODO implement
		Scene::update();
	}
};