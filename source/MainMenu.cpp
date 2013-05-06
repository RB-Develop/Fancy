#include <Engine/Scene.h>
#include <Engine/PrimitiveComponent.h>
#include <Engine/CameraComponent.h>
#include <Engine/UIBuilder.h>
#include <Engine/Core.h>
#include "PacketHandler.h"
#include "MenuEventReceiver.h"

class MainMenu : public Scene
{
private:
	IrrSmgr* _smgr;
	CameraComponent* camera;
	UIBuilder* uiBuilder;
	GUIButton* button;
	PacketHandler* _packetHandler;
	MenuEventReceiver* receiver;
	SAppContext context;
public:
	MainMenu(IrrSmgr* smgr, IrrDevice* device, UIBuilder* ui, PacketHandler* packetHandler) : Scene("MainMenu"), _smgr(smgr), uiBuilder(ui), _packetHandler(packetHandler)
	{
		context.device = device;
		context.packetHandler = packetHandler;

		receiver = new MenuEventReceiver(context);
		camera = new CameraComponent(smgr);
		camera->createCamera(CameraComponent::THIRD_PERSON);
		button = uiBuilder->createButton(150, 150, 150, 30, GUI_ID_NEW_LOBBY, 0, L"New lobby");
		device->setEventReceiver(receiver);
	}

	~MainMenu()
	{
		_smgr = NULL;
		camera = NULL;
		uiBuilder = NULL;
		_packetHandler = NULL;
	}

	void update()
	{
		Scene::update();
	}
};