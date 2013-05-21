#ifndef FANCY_MENU_RECEIVER
#define FANCY_MENU_RECEIVER

#include <iostream>

#include <Irrlicht/irrlicht.h>

#include <Engine/Core.h>
#include <Engine/Interface.h>

#include <NetworkData.h>
#include "NetworkHandler.h"

struct SAppContext
{
	fancy::Core *core;
	fancy::scene::Scene* currentScene;
	NetworkHandler* net;
	bool createNew;
};

enum
{
	GUI_ID_QUIT_BUTTON = 101,
	GUI_ID_GAME_SCENE,
	GUI_ID_NEW_LOBBY,
	GUI_ID_EDIT_NAME,
	GUI_ID_CONFIRM_NAME,
	GUI_ID_LOBBY_LIST,
	GUI_ID_REFRESH_LOBBYLIST
};

class MenuEventReceiver : public irr::IEventReceiver
{
private:
	SAppContext& _context;
public:
	MenuEventReceiver(SAppContext& context);
	~MenuEventReceiver();

	virtual bool OnEvent(const irr::SEvent& event);
};

#endif