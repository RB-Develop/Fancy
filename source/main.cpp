#include <iostream>

#include <Engine/FancyEngine.h>

#include "NetworkHandler.h"
#include "NameSelection.cpp"

using namespace std;
using namespace fancy;
using namespace fancy::network;

int main()
{
	Core* core = new Core(800, 600, 32);
	Interface* f_interface = new Interface(core->getGuiEnv(), core->getDriver());

	NetworkHandler* networkHandler = new NetworkHandler();

	core->setActiveScene(new NameSelection(core, f_interface, networkHandler));	

	irr::u32 then = core->getDevice()->getTimer()->getTime();

	while (core->getDevice()->run())
	{
		const irr::u32 now = core->getDevice()->getTimer()->getTime();
        const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f; // Time in seconds
        then = now;

		networkHandler->run();
		if (core->getDevice()->isWindowActive())
        {
			core->update(frameDeltaTime);
			core->draw(255, 255, 255, 255);
            int fps = core->getDriver()->getFPS();
        }
        else
            core->getDevice()->yield();
	}
	core->getDevice()->drop();
	return 0;
}