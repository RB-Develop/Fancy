#ifndef FANCY_CAMERA_COMP
#define FANCY_CAMERA_COMP

#include <Engine/Component.h>

namespace fancy {
	namespace object {

		class CameraComponent : public Component
		{
		public:
			enum CameraType {
				THIRD_PERSON,
				FIRST_PERSON,
				MAYA
			};

			CameraComponent(irr::scene::ISceneManager*, CameraType type);
			~CameraComponent();

			irr::scene::ICameraSceneNode* getCameraNode();
		private:
			irr::SKeyMap keyMap[8];
			irr::scene::ISceneManager* smgr;
			irr::scene::ICameraSceneNode* cameraNode;

			void createCamera(CameraType type, irr::scene::ISceneNode* parent = 0, irr::f32 rotateSpeed = 50.0f, irr::f32 moveSpeed = 0.15f);
		};

	}
}

#endif