#include <Engine/FancyEngine.h>

#include "MainMenu.cpp"
#include "ExtraScene.cpp"

int main()
{
	InputManager appReceiver;
	
	Core* core = new Core(800, 600, 32, &appReceiver);
	UIBuilder* uiBuilder = new UIBuilder(core->getGuiEnv());

	SceneManager* sceneManager = new SceneManager(core->getSmgr());
	sceneManager->setActiveScene(new MainMenu(core->getSmgr(), uiBuilder));	
		
	while (core->getDevice()->run())
	{
		if (appReceiver.isKeyboardButtonDown(irr::KEY_ESCAPE))
		{
			core->getSmgr()->getActiveCamera()->setInputReceiverEnabled(false);
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