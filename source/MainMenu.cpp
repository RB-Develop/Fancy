#include <Engine/Scene.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/CameraComponent.h>
#include <Engine/UIBuilder.h>
#include <Engine/Core.h>

class MainMenu : public Scene
{
private:
	IrrSmgr* smgr;
	CameraComponent* camera;
	UIBuilder* uiBuilder;
	GUIButton* button;
public:
	MainMenu(IrrSmgr* smgr, UIBuilder* ui) : Scene("MainMenu"), uiBuilder(ui)
	{
		camera = new CameraComponent(smgr);
		camera->createCamera(CameraComponent::THIRD_PERSON);
		button = uiBuilder->createButton(150, 150, 150, 30, 0, L"Waddap, new button");
		this->smgr = smgr;
	}

	~MainMenu()
	{
		smgr = NULL;
		camera = NULL;
		uiBuilder = NULL;
	}

	void update()
	{
		Scene::update();
	}
};