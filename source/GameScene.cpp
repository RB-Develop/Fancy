#include <Engine/Scene.h>
#include <Engine/Interface.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/CameraComponent.h>
#include <Engine/Core.h>
#include <Engine/Skybox.h>

#include "NetworkHandler.h"

using namespace fancy;
using namespace fancy::scene;
using namespace fancy::object;
using namespace fancy::gui;

class GameScene : public Scene
{
private:
	Core* _core;
public:
	GameScene(Core* core, Interface* ui, NetworkHandler* net) : Scene("ExtraMenu")
	{
		_core = core;
	}

	~GameScene()
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