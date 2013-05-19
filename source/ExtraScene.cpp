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
		_core = core;
	}

	~ExtraScene()
	{
		_core = NULL;
	}

	void init()
	{
		addComponent(new CameraComponent(_core->getSmgr(), CameraComponent::FIRST_PERSON));
		addComponent(new PrimitiveComponent(_core->getSmgr(), PrimitiveComponent::PRIM_SPHERE, 2));
		addComponent(new Skybox(_core->getSmgr(), _core->getDriver(), "sky")); 
	}

	void requestNextScene()
	{
	}

	void notify(void* data)
	{

	}

	void update()
	{
		//TODO implement
		Scene::update();
	}
};