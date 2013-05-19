#ifndef FANCY_PACKET_RECEIVER
#define FANCY_PACKET_RECEIVER

#include <iostream>
#include <windows.h>

#include <SFML/Network.hpp>
#include <NetworkData.h>

#include "Subject.h"

class PacketReceiver : public Subject
{
public:
	PacketReceiver();
	virtual ~PacketReceiver();

	void run();
	void respond(sf::Packet*, sf::IpAddress*, const unsigned short clientPort);
	
	FancyPacket* getPacket();
	sf::IpAddress* getSender();
	unsigned short getSenderPort();
private:
	unsigned short port;

	sf::UdpSocket _socket;
	sf::IpAddress sender;

	sf::Packet _serializedPacket;
	FancyPacket packet;
};

#endif