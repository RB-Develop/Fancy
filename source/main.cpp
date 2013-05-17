#include <Engine/FancyEngine.h>
#include <iostream>
#include <NetworkData.h>

#include "NetworkHandler.h"
#include "MainMenu.cpp"
#include "NameSelection.cpp"

using namespace fancy;
using namespace fancy::network;


int main()
{
	Core* core = new Core(800, 600, 32);
	Interface* f_interface = new Interface(core->getGuiEnv(), core->getDriver());
	NetworkHandler* networkHandler = new NetworkHandler();

	core->setActiveScene(new NameSelection(core, f_interface));	

	Networker::instance()->openUdpSocket(9125);

	while (core->getDevice()->run())
	{
		networkHandler->run();
		if (core->getDevice()->isWindowActive())
        {
			core->draw(255, 255, 255, 255);
            int fps = core->getDriver()->getFPS();
        }
        else
            core->getDevice()->yield();
	}
	core->getDevice()->drop();
	return 0;
}