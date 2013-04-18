#include <Engine\Camera.h>

Camera::Camera(ISceneManager* smgr)
{
	this->smgr = smgr;
}

ICameraSceneNode* Camera::getCameraNode()
{
	return cameraNode;
}

void Camera::createCamera(CameraType type, ISceneNode* parent)
{
	switch(type)
	{
	case(FIRST_PERSON):
		smgr->addCameraSceneNodeFPS(parent, 10.0f);
		break;
	case(THIRD_PERSON):
		smgr->addCameraSceneNode(parent);
		break;
	case(MAYA):
		smgr->addCameraSceneNodeMaya(parent);
		break;
	}
}

Camera::~Camera()
{
}
