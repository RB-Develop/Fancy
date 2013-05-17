#include <Engine/Scene.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/CameraComponent.h>
#include <Engine/Interface.h>
#include <Engine/Core.h>
#include "MenuEventReceiver.h"

using namespace fancy;
using namespace fancy::scene;
using namespace fancy::gui;
using namespace fancy::object;

class MainMenu : public Scene
{
private:
	Core* _core;
	Interface* _interface;
	SAppContext context;
public:
	MainMenu(Core* core, Interface* ui) : Scene("MainMenu"), _core(core), _interface(ui)
	{
		context.core = _core;

		_core->addCustomReceiver(new MenuEventReceiver(context));

		addComponent(new CameraComponent(_core->getSmgr(), CameraComponent::THIRD_PERSON));
		
		_interface->addImage("../assets/galaxy.jpg", 0, 0);
		_interface->addImage("../assets/logo.png", 40, 50);

		_interface->createButton(core->getDriver()->getScreenSize().Width/2-75, 150, 
			150, 30, 
			GUI_ID_NEW_LOBBY, 0, L"New lobby");

		_interface->createButton(core->getDriver()->getScreenSize().Width/2-75, 250, 
			150, 30, 
			GUI_ID_GAME_SCENE, 0, L"Start scene");
	}

	~MainMenu()
	{
		_core->resetReceiver();
		_core = NULL;

		_interface->resetInterface();
		_interface = NULL;
	}

	void update()
	{
		Scene::update();
	}
};