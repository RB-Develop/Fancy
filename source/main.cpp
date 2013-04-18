#include <Irrlicht/irrlicht.h>
#include <Engine/FancyEngine.h>

#include "CAppReceiver.cpp"

using namespace irr;
using namespace core;
using namespace video;
using namespace gui;

int main()
{
	InputManager appReceiver;

	IrrlichtDevice* device = createDevice(EDT_OPENGL,
		dimension2d<u32>(640, 480), 16,
		false, false, true, &appReceiver);

	if (!device)
		return 1;

	IVideoDriver* driver = device->getVideoDriver();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	ISceneManager* smgr = device->getSceneManager();

	Camera* camera = new Camera(smgr);
	camera->createCamera(Camera::FIRST_PERSON);
	smgr->addCubeSceneNode(10.0f, NULL, 1, vector3df(10, 0, 10));

	while (device->run())
	{
		if (appReceiver.isKeyboardButtonDown(KEY_ESCAPE))
		{
			device->closeDevice();
			return 0;
		}
		if (device->isWindowActive())
        {
            driver->beginScene(true, true, video::SColor(255,200,200,200));
            smgr->drawAll();
            driver->endScene();

            int fps = driver->getFPS();
        }
        else
            device->yield();
	}
	device->drop();
	return 0;
}