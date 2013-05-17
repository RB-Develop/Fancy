#include "MenuEventReceiver.h"

#include "ExtraScene.cpp"
#include "MainMenu.cpp"

using namespace irr;
using namespace irr::core;
using namespace irr::gui;
using namespace irr::video;

using namespace fancy::network;

MenuEventReceiver::MenuEventReceiver(SAppContext& context) : _context(context) 
{

}

MenuEventReceiver::~MenuEventReceiver()
{

}

bool MenuEventReceiver::OnEvent(const SEvent& event)
{
	if (event.EventType == EET_GUI_EVENT)
	{
		s32 id = event.GUIEvent.Caller->getID();
		IGUIEnvironment* env = _context.core->getDevice()->getGUIEnvironment();
		FancyPacket packet;

		switch(event.GUIEvent.EventType)
		{
		case EGET_BUTTON_CLICKED:
			switch(id)
			{
			case GUI_ID_QUIT_BUTTON:
				_context.core->getDevice()->closeDevice();
				return true;
			case GUI_ID_GAME_SCENE:
				_context.core->setActiveScene(new ExtraScene(_context.core));
				return true;
			case GUI_ID_NEW_LOBBY:
				return true;
			case GUI_CONFIRM_NAME:
				printf("Name given is: %ls. \n", _context.nameBox->getText());
				_context.core->setActiveScene(new MainMenu(_context.core, _context.f_interface));
				return true;
			default:
				return false;
			}
			break;
		default:
			break;
		}
	}

	return false;
}