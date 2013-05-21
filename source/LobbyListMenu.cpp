#include <Engine/Interface.h>
#include <Engine/Scene.h>
#include <Engine/Core.h>

#include "NetworkHandler.h"
#include "MenuEventReceiver.h"
#include "GameScene.cpp"

using namespace fancy;
using namespace fancy::scene;
using namespace fancy::network;
using namespace fancy::gui;

class LobbyListMenu : public Scene
{
private:
	Core* _core;
	Interface* _interface;
	NetworkHandler* _net;

	SAppContext context;
public:
	LobbyListMenu(Core* core, Interface* ui, NetworkHandler* net) : Scene("LobbyListMenu"), _core(core), _interface(ui), _net(net)
	{
		context.core = _core;
		context.currentScene = this;
		context.net = _net;

		_net->attachScene(this);
	}

	~LobbyListMenu()
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
		_net->sendPacketType(PacketTypes::REQUEST_LOBBY_LIST);

		_interface->addImage("../assets/galaxy.jpg", 0, 0);
		_interface->addImage("../assets/logo.png", 40, 50);

		_interface->addListBox(30, 150, _core->getDriver()->getScreenSize().Width - 60, _core->getDriver()->getScreenSize().Height - 300, GUI_ID_LOBBY_LIST, 0, true);

		_interface->createButton(30, _core->getDriver()->getScreenSize().Height - 100, 150, 65,	GUI_ID_REFRESH_LOBBYLIST, 0, L"Refresh");

		_core->addCustomReceiver(new MenuEventReceiver(context));
	}

	void requestNextScene()
	{
		_core->setActiveScene(new GameScene(_core, _interface, _net));
	}

	void notify(void* data)
	{
		irr::gui::IGUIListBox* listBox = (irr::gui::IGUIListBox* )_interface->getElementWithId(GUI_ID_LOBBY_LIST);
	}

	void update()
	{
		Scene::update();
	}
};