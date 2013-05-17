#ifndef FANCY_CLIENT_NETWORKHANDLER
#define FANCY_CLIENT_NETWORKHANDLER

#include <iostream>

#include <NetworkData.h>
#include <Engine/Networker.h>

class NetworkHandler
{
public:
	NetworkHandler();
	~NetworkHandler();

	void run();

	FancyPacket* getPacket();
private:
	FancyPacket _receivedPacket;
};

#endif