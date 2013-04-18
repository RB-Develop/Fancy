#include <Engine/Scene.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/Camera.h>

class ExtraScene : public Scene
{
private:
	ISceneManager* smgr;
	Camera* camera;
public:
	ExtraScene(ISceneManager* smgr) : Scene("ExtraMenu")
	{
		camera = new Camera(smgr);
		camera->createCamera(Camera::FIRST_PERSON);
		addComponent(new PrimitiveComponent(smgr, PrimitiveComponent::PRIM_SPHERE, 2));
		this->smgr = smgr;
	}

	~ExtraScene()
	{
		delete camera;
	}

	void update()
	{
		//TODO implement
		Scene::update();
	}
};