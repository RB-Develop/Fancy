#ifndef FANCY_PACKET_RECEIVER
#define FANCY_PACKET_RECEIVER

#include <iostream>
#include <windows.h>

#include <SFML/Network.hpp>
#include <NetworkData.h>

#include "CallbackMediator.h"

class PacketReceiver
{
private:
	char network_data[MAX_PACKET_SIZE];
	unsigned short port;

	std::size_t received;
	sf::UdpSocket socket;
	sf::IpAddress sender;

	FancyPacket packet;
	CallbackMediator* _mediator;
public:
	PacketReceiver(CallbackMediator* mediator);
	~PacketReceiver();

	void run();

	void receiveFromClients();
};

#endif