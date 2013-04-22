#include <Engine/Scene.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/CameraComponent.h>
#include <Engine/Core.h>

class ExtraScene : public Scene
{
private:
	IrrSmgr* smgr;
	CameraComponent* camera;
public:
	ExtraScene(IrrSmgr* smgr) : Scene("ExtraMenu")
	{
		camera = new CameraComponent(smgr);
		camera->createCamera(CameraComponent::FIRST_PERSON);
		addComponent(camera);
		addComponent(new PrimitiveComponent(smgr, PrimitiveComponent::PRIM_SPHERE, 2));
		this->smgr = smgr;
	}

	~ExtraScene()
	{
		smgr = NULL;
		camera = NULL;
	}

	void update()
	{
		//TODO implement
		Scene::update();
	}
};