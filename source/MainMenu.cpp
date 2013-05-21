#include <Engine/Scene.h>
#include <Engine/Interface.h>
#include <Engine/Core.h>

#include "MenuEventReceiver.h"
#include "NetworkHandler.h"

#include "LobbyListMenu.cpp"

using namespace fancy;
using namespace fancy::scene;
using namespace fancy::gui;
using namespace fancy::object;

class MainMenu : public Scene
{
private:
	Core* _core;
	Interface* _interface;
	NetworkHandler* _net;
	SAppContext context;
public:
	MainMenu(Core* core, Interface* ui, NetworkHandler* net) : Scene("MainMenu"), _core(core), _interface(ui), _net(net)
	{
		context.core = _core;
		context.currentScene = this;

		_net->attachScene(this);
	}

	~MainMenu()
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

		_interface->createButton(_core->getDriver()->getScreenSize().Width/2-75, 150, 
			150, 30, 
			GUI_ID_LOBBY_LIST, 0, L"Join a game.");

		_interface->createButton(_core->getDriver()->getScreenSize().Width/2-75, 250, 
			150, 30, 
			GUI_ID_NEW_LOBBY, 0, L"Start new game.");

		_core->addCustomReceiver(new MenuEventReceiver(context));
	}

	void requestNextScene()
	{
		if(context.createNew == true) {
			_net->sendPacketType(PacketTypes::REQUEST_NEW_LOBBY);
			printf("New lobby\n");
		}
		else {
			_core->setActiveScene(new LobbyListMenu(_core, _interface, _net));
		}
	}

	void notify(void* data){}

	void update()
	{
		Scene::update();
	}
};