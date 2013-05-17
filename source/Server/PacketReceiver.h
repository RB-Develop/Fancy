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
	void respond(const char* packet_data, const unsigned int packet_size, sf::IpAddress* clientAdress, const unsigned int clientPort);
	
	FancyPacket* getPacket();
	sf::IpAddress* getSender();
	unsigned short getSenderPort();
private:
	char network_data[MAX_PACKET_SIZE];
	unsigned short port;

	std::size_t received;
	sf::UdpSocket _socket;
	sf::IpAddress sender;

	FancyPacket packet;
};

#endif