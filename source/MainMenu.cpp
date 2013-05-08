#include <Engine/Scene.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/CameraComponent.h>
#include <Engine/GuiBuilder.h>
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
	GuiBuilder* _uiBuilder;
	GUIButton* button;
	SAppContext context;
public:
	MainMenu(Core* core, GuiBuilder* ui) : Scene("MainMenu"), _core(core), _uiBuilder(ui)
	{
		context.core = _core;

		_core->addCustomReceiver(new MenuEventReceiver(context));

		addComponent(new CameraComponent(_core->getSmgr(), CameraComponent::THIRD_PERSON));
		
		_uiBuilder->createButton(150, 150, 150, 30, GUI_ID_NEW_LOBBY, 0, L"New lobby");
		_uiBuilder->createButton(150, 250, 150, 30, GUI_ID_GAME_SCENE, 0, L"Start scene");
	}

	~MainMenu()
	{
		_core->resetReceiver();
		_core = NULL;
		_uiBuilder = NULL;
	}

	void update()
	{
		Scene::update();
	}
};