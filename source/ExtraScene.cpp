#include <Engine/Scene.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/CameraComponent.h>
#include <Engine/Core.h>

using namespace fancy;
using namespace fancy::scene;
using namespace fancy::object;

class ExtraScene : public Scene
{
private:
	IrrSmgr* smgr;
public:
	ExtraScene(IrrSmgr* smgr) : Scene("ExtraMenu")
	{
		addComponent(new CameraComponent(smgr, CameraComponent::FIRST_PERSON));
		addComponent(new PrimitiveComponent(smgr, PrimitiveComponent::PRIM_SPHERE, 2));
		this->smgr = smgr;
	}

	~ExtraScene()
	{
		smgr = NULL;
	}

	void update()
	{
		//TODO implement
		Scene::update();
	}
};