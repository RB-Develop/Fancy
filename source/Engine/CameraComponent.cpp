#include <Engine\CameraComponent.h>

using namespace irr;
using namespace scene;

CameraComponent::CameraComponent(ISceneManager* smgr) : Component("Camera")
{
	this->smgr = smgr;
}

CameraComponent::~CameraComponent()
{
	smgr->addToDeletionQueue(cameraNode);
	smgr = NULL;
}

ICameraSceneNode* CameraComponent::getCameraNode()
{
	return cameraNode;
}

void CameraComponent::createCamera(CameraType type, ISceneNode* parent)
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
