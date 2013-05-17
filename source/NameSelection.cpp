#include <Engine/Scene.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/Interface.h>
#include <Engine/Core.h>
#include "MenuEventReceiver.h"

using namespace fancy;
using namespace fancy::scene;
using namespace fancy::gui;
using namespace fancy::object;

class NameSelection : public Scene
{
private:
	Core* _core;
	Interface* _interface;
	SAppContext context;
public:
	NameSelection(Core* core, Interface* ui) : Scene("NameSelection"), _core(core), _interface(ui)
	{
		context.core = _core;
		context.f_interface = _interface;
	}

	~NameSelection()
	{
		_core->resetReceiver();
		_core = NULL;

		_interface->resetInterface();
		_interface = NULL;
	}

	void init()
	{
		_interface->addImage("../assets/galaxy.jpg", 0, 0);
		_interface->addImage("../assets/logo.png", 40, 50);

		_interface->addEditBox(_core->getDriver()->getScreenSize().Width/2-125, 250,
			250, 30,
			GUI_EDIT_NAME, 0, L"", false);

		_interface->createButton(_core->getDriver()->getScreenSize().Width/2-75, 300, 
			150, 30, 
			GUI_CONFIRM_NAME, 0, L"Confirm");

		context.nameBox = _interface->getElementWithId(GUI_EDIT_NAME);

		_core->addCustomReceiver(new MenuEventReceiver(context));
	}

	void update()
	{
		Scene::update();
	}
};