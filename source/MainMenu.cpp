#include <Engine/Scene.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/CameraComponent.h>
#include <Engine/core.h>

class MainMenu : public Scene
{
private:
	IrrSmgr* smgr;
	CameraComponent* camera;
public:
	MainMenu(IrrSmgr* smgr) : Scene("MainMenu")
	{
		camera = new CameraComponent(smgr);
		camera->createCamera(CameraComponent::FIRST_PERSON);
		addComponent(new PrimitiveComponent(smgr, PrimitiveComponent::PRIM_CUBE, 5));

		this->smgr = smgr;
	}

	~MainMenu()
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