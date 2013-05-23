#ifndef FANCY_UDP_HANDLER
#define FANCY_UDP_HANDLER

#include <iostream>

#include <SFML/Network.hpp>
#include <NetworkData.h>

class UdpHandler
{
public:
	UdpHandler();
	~UdpHandler();

	sf::Packet* receiveData();
	sf::IpAddress* getSender();
	unsigned short getSenderPort();

	void sendData(sf::Packet* packet, sf::IpAddress* address, unsigned short clientPort);
private:
	unsigned short _port;
	sf::UdpSocket _socket;
	sf::IpAddress _sender;
};

#endif