#include <Engine\Camera.h>

Camera::Camera(ISceneManager* smgr)
{
	this->smgr = smgr;
}

Camera::~Camera()
{
	smgr->addToDeletionQueue(cameraNode);
	smgr = NULL;
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
		cameraNode = smgr->addCameraSceneNodeFPS(parent, 10.0f);
		break;
	case(THIRD_PERSON):
		cameraNode = smgr->addCameraSceneNode(parent);
		break;
	case(MAYA):
		cameraNode = smgr->addCameraSceneNodeMaya(parent);
		break;
	}
}
