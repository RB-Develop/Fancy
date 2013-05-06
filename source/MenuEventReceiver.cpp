#include "MenuEventReceiver.h"

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
		IGUIEnvironment* env = Context.device->getGUIEnvironment();

		switch(event.GUIEvent.EventType)
		{
		case EGET_BUTTON_CLICKED:
			switch(id)
			{
			case GUI_ID_QUIT_BUTTON:
				Context.device->closeDevice();
				return true;
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