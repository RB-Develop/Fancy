#include <Engine/FancyEngine.h>
#include <iostream>

#include "MainMenu.cpp"
#include "PacketHandler.h"

int main()
{
	PacketHandler packetHandler;

	Core* core = new Core(800, 600, 32);
	UIBuilder* uiBuilder = new UIBuilder(core->getGuiEnv());

	core->setActiveScene(new MainMenu(core, uiBuilder, &packetHandler));	

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