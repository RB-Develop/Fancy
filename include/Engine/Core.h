#ifndef FANCY_CORE
#define FANCY_CORE

#include <Irrlicht/irrlicht.h>

typedef irr::IrrlichtDevice IrrDevice;
typedef irr::video::IVideoDriver IrrDriver;
typedef irr::gui::IGUIEnvironment IrrGuiEnv;
typedef irr::scene::ISceneManager IrrSmgr;

class Core
{
private:
	IrrDevice* device;
	IrrDriver* driver;
	IrrGuiEnv* guiEnv;
	IrrSmgr* smgr;

	irr::u32 width, height, bitDepth;
	irr::IEventReceiver* appReceiver;
public:
	/*!
	* @function Core 
	*	Constructor for the Fancy core. This handles communication with the Irrlicht 3D engine, physics and networking.
	*/
	Core(irr::u32 width, irr::u32 height, irr::u32 bitDepth, irr::IEventReceiver* receiver);
	~Core();

	void draw(irr::u32 alpha, irr::u32 red, irr::u32 green, irr::u32 blue);

	IrrDevice* getDevice() { return device; };
	IrrDriver* getDriver() { return driver; };
	IrrGuiEnv* getGuiEnv() { return guiEnv; };
	IrrSmgr* getSmgr() { return smgr; };
};

#endif