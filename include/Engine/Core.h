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
public:
	/*!
	* @function Core 
	*	Constructor for the Fancy core. This handles communication with the Irrlicht 3D engine, physics and networking.
	* @param ISceneManager* 
	*	Pass in the pointer to your Irrlicht scene manager.
	* @param PrimitiveType
	*	Type of the primitive to create. It can be a Cube (PRIM_CUBE) or Sphere (PRIM_SPHERE).
	* @param Size
	*	The size of the primitive. For a sphere it is the radius, for a cube it is the halfsize.
	* @param Position
	*	The position in the game world. It is described using an Irrlicht vector3df taking floats.
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