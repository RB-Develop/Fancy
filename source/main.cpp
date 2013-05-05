#include <Engine/FancyEngine.h>
#include <SFML/Network.hpp>
#include <NetworkData.h>

#include "MainMenu.cpp"
#include "ExtraScene.cpp"

int main()
{
	InputManager appReceiver;
	
	Core* core = new Core(800, 600, 32, &appReceiver);
	UIBuilder* uiBuilder = new UIBuilder(core->getGuiEnv());

	SceneManager* sceneManager = new SceneManager(core->getSmgr());
	sceneManager->setActiveScene(new MainMenu(core->getSmgr(), uiBuilder));	
		
	sf::UdpSocket socket;

	// bind the socket to a port
	if (socket.bind(54001) != sf::Socket::Done)
	{
		printf("Cannot bind the socket [Client]\n");
	}

	sf::IpAddress recipient = "localhost";
	
	const unsigned int packet_size = sizeof(FancyPacket);
    char packet_data[packet_size];

	FancyPacket packet;
	packet.packet_type = PacketTypes::REQUEST_NEW_LOBBY;

	packet.serialize(packet_data);

	unsigned short port = 54000;
	
	if (socket.send(packet_data, 100, recipient, port) != sf::Socket::Done)
	{
		printf("error sending message [Client]\n");
	}

	while (core->getDevice()->run())
	{
		if (appReceiver.isKeyboardButtonDown(irr::KEY_ESCAPE))
		{
			core->getSmgr()->getActiveCamera()->setInputReceiverEnabled(false);
		}
		if (core->getDevice()->isWindowActive())
        {
			core->draw(255,255,255,255);
            int fps = core->getDriver()->getFPS();
        }
        else
            core->getDevice()->yield();
	}
	core->getDevice()->drop();
	return 0;
}