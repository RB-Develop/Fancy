#ifndef FANCY_SKYBOX_COMP
#define FANCY_SKYBOX_COMP

#include <Engine/Component.h>
#include <Irrlicht/irrlicht.h>
#include <string>

namespace fancy {
	namespace object {

		class Skybox : public Component
		{
		public:
			Skybox(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver, std::string imagePrefix);
			~Skybox();
		private:
			irr::scene::ISceneManager* _smgr;
			irr::scene::ISceneNode* _skybox;
			std::string basePath;
		};

	}
}

#endif