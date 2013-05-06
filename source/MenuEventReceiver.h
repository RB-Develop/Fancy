#ifndef FANCY_MENU_RECEIVER
#define FANCY_MENU_RECEIVER

#include <Irrlicht/irrlicht.h>
#include <Engine/Core.h>
#include <NetworkData.h>
#include "PacketHandler.h"


struct SAppContext
{
	Core *core;
	PacketHandler *packetHandler;
};

enum
{
	GUI_ID_QUIT_BUTTON = 101,
	GUI_ID_GAME_SCENE,
	GUI_ID_NEW_LOBBY
};

class MenuEventReceiver : public irr::IEventReceiver
{
private:
	SAppContext & Context;
public:
	MenuEventReceiver(SAppContext& context);
	~MenuEventReceiver();

	virtual bool OnEvent(const irr::SEvent& event);
};

#endif