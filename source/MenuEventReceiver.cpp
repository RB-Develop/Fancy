#include "MenuEventReceiver.h"

#include "ExtraScene.cpp"

using namespace irr;
using namespace core;
using namespace gui;
using namespace video;


MenuEventReceiver::MenuEventReceiver(SAppContext& context) : Context(context) 
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
		IGUIEnvironment* env = Context.core->getDevice()->getGUIEnvironment();

		switch(event.GUIEvent.EventType)
		{
		case EGET_BUTTON_CLICKED:
			switch(id)
			{
			case GUI_ID_QUIT_BUTTON:
				Context.core->getDevice()->closeDevice();
				return true;
			case GUI_ID_GAME_SCENE:
				Context.core->setActiveScene(new ExtraScene(Context.core->getSmgr()));
				break;
			case GUI_ID_NEW_LOBBY:
				Context.packetHandler->sendPacket(PacketTypes::REQUEST_NEW_LOBBY, "René");
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