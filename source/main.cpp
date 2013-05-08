#include <Engine/FancyEngine.h>
#include <iostream>

#include "MainMenu.cpp"

using namespace fancy;

int main()
{
	Core* core = new Core(800, 600, 32);
	GuiBuilder* guiBuilder = new GuiBuilder(core->getGuiEnv());

	core->setActiveScene(new MainMenu(core, guiBuilder));	

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