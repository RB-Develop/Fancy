#ifndef FANCY_CAMERA_COMP
#define FANCY_CAMERA_COMP

#include <Engine/Component.h>

class CameraComponent : public Component
{
private:
	irr::scene::ISceneManager* smgr;
	irr::scene::ICameraSceneNode* cameraNode;
public:
	enum CameraType {
		THIRD_PERSON,
		FIRST_PERSON,
		MAYA
	};

	CameraComponent(irr::scene::ISceneManager*);
	~CameraComponent();
	void createCamera(CameraType, irr::scene::ISceneNode* = 0);
	irr::scene::ICameraSceneNode* getCameraNode();
};


#endif