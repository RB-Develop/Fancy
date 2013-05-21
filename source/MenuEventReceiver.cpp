#include "MenuEventReceiver.h"

using namespace irr;
using namespace irr::core;
using namespace irr::gui;
using namespace irr::video;

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

		switch(event.GUIEvent.EventType)
		{
		case EGET_BUTTON_CLICKED:
			switch(id)
			{
			case GUI_ID_QUIT_BUTTON:
				_context.core->getDevice()->closeDevice();
				return true;
			case GUI_ID_GAME_SCENE:
				_context.currentScene->requestNextScene();
				return true;
			case GUI_ID_NEW_LOBBY:
				_context.createNew = true;
				_context.currentScene->requestNextScene();
				return true;
			case GUI_ID_LOBBY_LIST:
				_context.createNew = false;
				_context.currentScene->requestNextScene();
				return true;
			case GUI_ID_REFRESH_LOBBYLIST:
				_context.net->sendPacketType(PacketTypes::REQUEST_LOBBY_LIST);
				return true;
			case GUI_ID_CONFIRM_NAME:
				_context.currentScene->requestNextScene();
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