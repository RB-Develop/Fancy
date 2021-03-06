#ifndef FANCY_CORE
#define FANCY_CORE

#include <Irrlicht/irrlicht.h>
#include "Scene.h"
#include "InputManager.h"
namespace fancy 
{
	typedef irr::IrrlichtDevice IrrDevice;
	typedef irr::video::IVideoDriver IrrDriver;
	typedef irr::gui::IGUIEnvironment IrrGuiEnv;
	typedef irr::scene::ISceneManager IrrSmgr;

	class Core
	{
	private:
		scene::Scene* activeScene;

		IrrDevice* device;
		IrrDriver* driver;
		IrrGuiEnv* guiEnv;
		IrrSmgr* smgr;

		irr::u32 width, height, bitDepth;

		input::InputManager* appReceiver;
	public:
		/*!
		* @function Core 
		*	Constructor for the Fancy core. This handles communication with the Irrlicht 3D engine, physics and networking.
		*/
		Core(irr::u32 width, irr::u32 height, irr::u32 bitDepth);
		~Core();

		void draw(irr::u32 alpha, irr::u32 red, irr::u32 green, irr::u32 blue);
		void update(irr::s32 duration);

		void addCustomReceiver(irr::IEventReceiver* receiver);
		void resetReceiver();

		void setActiveScene(scene::Scene* scene);

		IrrDevice* getDevice() { return device; };
		IrrDriver* getDriver() { return driver; };
		IrrGuiEnv* getGuiEnv() { return guiEnv; };
		IrrSmgr* getSmgr() { return smgr; };
	};
}
#endif