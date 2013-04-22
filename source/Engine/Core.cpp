#include <Engine/core.h>

using namespace irr;
using namespace core;
using namespace video;

Core::Core(u32 width, u32 height, u32 bitDepth, IEventReceiver* receiver)
{
	device = createDevice(EDT_OPENGL, dimension2d<u32>(width, height), bitDepth, false, false, true, receiver);

	if (!device)
		exit(1);

	driver = device->getVideoDriver();
	guiEnv = device->getGUIEnvironment();
	smgr = device->getSceneManager();
}

Core::~Core()
{
}

void Core::draw(u32 alpha, u32 red, u32 green, u32 blue)
{
	driver->beginScene(true, true, video::SColor(255,200,200,200));
	smgr->drawAll();
	driver->endScene();
}