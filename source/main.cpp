#include <Engine/FancyEngine.h>
#include <iostream>

#include "MainMenu.cpp"

using namespace fancy;
using namespace fancy::network;


int main()
{
	Core* core = new Core(800, 600, 32);
	GuiBuilder* guiBuilder = new GuiBuilder(core->getGuiEnv());

	core->setActiveScene(new MainMenu(core, guiBuilder));	

	Networker::instance()->openUdpSocket(9125);

	while (core->getDevice()->run())
	{
		if (core->getDevice()->isWindowActive())
        {
			core->draw(255,255,255,255);
            int fps = core->getDriver()->getFPS();
        }
        else
            core->getDevice()->yield();
	}
	core->getDevice()->drop();
	return 0;
}