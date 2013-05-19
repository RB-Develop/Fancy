#include <Engine/Scene.h>
#include <Engine/Interface.h>
#include <Engine/Core.h>

#include "MainMenu.cpp"
#include "MenuEventReceiver.h"
#include "NetworkHandler.h"

using namespace fancy;
using namespace fancy::scene;
using namespace fancy::gui;
using namespace fancy::object;

class NameSelection : public Scene
{
private:
	Core* _core;
	Interface* _interface;
	NetworkHandler* _net;

	bool _sceneRequest, _allowNextScene;

	SAppContext context;
public:
	NameSelection(Core* core, Interface* ui, NetworkHandler* net) : Scene("NameSelection"), _core(core), _interface(ui), _net(net)
	{
		context.core = _core;
		context.currentScene = this;

		_net->attachScene(this);
		_sceneRequest = _allowNextScene = false;
	}

	~NameSelection()
	{
		_net->detachScene(this);
		_net = NULL;

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

		_core->addCustomReceiver(new MenuEventReceiver(context));
	}

	void requestNextScene()
	{
		size_t i;
		char tempdata[25];
		wcstombs_s(&i, tempdata, _interface->getElementWithId(GUI_EDIT_NAME)->getText(), 24);
		std::string name = tempdata;
		_net->setUserName(name);
		_net->sendPacketType(PacketTypes::REGISTER_PLAYER);
		_sceneRequest = true;
	}

	void notify(void* data)
	{
		if(data == _net)
		{
			if(_net->getPacket()->packet_type == PacketTypes::REGISTER_SUCCES) 
				_allowNextScene = true;
			else
				_sceneRequest = false;
		}
	}

	void update()
	{
		if(_sceneRequest && _allowNextScene) {
			_core->setActiveScene(new MainMenu(_core, _interface, _net));
			return;
		}

		Scene::update();
	}
};