#include <Engine/FancyEngine.h>
#include <iostream>

#include "MainMenu.cpp"
#include "ExtraScene.cpp"
#include "PacketHandler.h"

int main()
{
	InputManager appReceiver;
	PacketHandler packetHandler;

	Core* core = new Core(800, 600, 32, &appReceiver);
	UIBuilder* uiBuilder = new UIBuilder(core->getGuiEnv());

	SceneManager* sceneManager = new SceneManager(core->getSmgr());
	sceneManager->setActiveScene(new MainMenu(core->getSmgr(), core->getDevice(), uiBuilder, &packetHandler));	

	wchar_t* hoi = L"xyz";
	char* haha[9];

	*haha = (char*)hoi;

	std::cout << "Output: " << haha << "\n";

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