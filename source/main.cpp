#include <Engine/FancyEngine.h>

#include "MainMenu.cpp"
#include "ExtraScene.cpp"

int main()
{
	InputManager appReceiver;
	
	Core* core = new Core(800, 600, 32, &appReceiver);

	SceneManager* sceneManager = new SceneManager(core->getSmgr());
	sceneManager->setActiveScene(new MainMenu(core->getSmgr()));
		
	while (core->getDevice()->run())
	{
		if (appReceiver.isKeyboardButtonDown(irr::KEY_ESCAPE))
		{
			core->getDevice()->closeDevice();
			return 0;
		}
		if (appReceiver.isKeyboardButtonDown(irr::KEY_SPACE))
		{
			sceneManager->setActiveScene(new ExtraScene(core->getSmgr()));
		}
		if (core->getDevice()->isWindowActive())
        {
			core->draw(255,200,200,200);

            int fps = core->getDriver()->getFPS();
        }
        else
            core->getDevice()->yield();
	}
	core->getDevice()->drop();
	return 0;
}