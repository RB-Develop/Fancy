#ifndef FANCY_MENU_RECEIVER
#define FANCY_MENU_RECEIVER

#include <iostream>

#include <Irrlicht/irrlicht.h>

#include <Engine/Core.h>
#include <Engine/Interface.h>
#include <Engine/Networker.h>
#include <NetworkData.h>

struct SAppContext
{
	fancy::Core *core;
	irr::gui::IGUIElement* nameBox;
	fancy::gui::Interface* f_interface;
};

enum
{
	GUI_ID_QUIT_BUTTON = 101,
	GUI_ID_GAME_SCENE,
	GUI_ID_NEW_LOBBY,
	GUI_EDIT_NAME,
	GUI_CONFIRM_NAME
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