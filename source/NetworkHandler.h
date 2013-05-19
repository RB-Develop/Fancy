#ifndef FANCY_CLIENT_NETWORKHANDLER
#define FANCY_CLIENT_NETWORKHANDLER

#include <iostream>
#include <string>
#include <list>

#include <NetworkData.h>
#include <Engine/Networker.h>
#include <Engine/Scene.h>

class NetworkHandler
{
public:
	NetworkHandler();
	~NetworkHandler();

	void run();
	void setUserName(std::string userName);
	void sendPacketType(unsigned int type);
	void attachScene(fancy::scene::Scene*);
	void detachScene(fancy::scene::Scene*);

	FancyPacket* getPacket();
private:
	std::string _userName;

	fancy::network::Networker* _networker;

	FancyPacket _receivedPacket;
	FancyPacket _sendPacket;
	const FancyPacket _nullPacket;

	sf::Packet _serializedPacket;

	std::list<fancy::scene::Scene*> _listeners;

	void onReceived();
};

#endif