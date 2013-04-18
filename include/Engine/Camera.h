#ifndef CAMERA
#define CAMERA

#include <Irrlicht/irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;

class Camera
{
private:
	ISceneManager* smgr;
	ICameraSceneNode* cameraNode;
public:
	enum CameraType {
		THIRD_PERSON,
		FIRST_PERSON,
		MAYA
	};

	Camera(ISceneManager*);
	~Camera();
	void createCamera(CameraType, ISceneNode* = NULL);
	ICameraSceneNode* getCameraNode();
};


#endif