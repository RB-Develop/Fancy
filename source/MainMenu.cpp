#include <Engine/Scene.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/Camera.h>

class MainMenu : public Scene
{
private:
	ISceneManager* smgr;
	Camera* camera;
public:
	MainMenu(ISceneManager* smgr) : Scene("MainMenu")
	{
		camera = new Camera(smgr);
		camera->createCamera(Camera::FIRST_PERSON);
		addComponent(new PrimitiveComponent(smgr, PrimitiveComponent::PRIM_CUBE, 5));

		this->smgr = smgr;
	}

	~MainMenu()
	{
		delete camera;
	}

	void update()
	{
		//TODO implement
		Scene::update();
	}
};