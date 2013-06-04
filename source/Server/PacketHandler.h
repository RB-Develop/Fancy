#ifndef FANCY_PACKET_RECEIVER
#define FANCY_PACKET_RECEIVER

#include <iostream>
#include <list>

#include <SFML/Network.hpp>
#include <NetworkData.h>

#include "Subject.h"
#include "UdpHandler.h"
#include "TcpHandler.h"

class PacketHandler : public Subject
{
public:
	PacketHandler(UdpHandler*, TcpHandler*);
	virtual ~PacketHandler();
	
	/*
	This function is used for sending UDP packets.
	*/
	void sendData(FancyPacket packet, std::string ipAddress, unsigned short port);

	/*
	This function is used for sending TCP packets.
	*/
	void sendData(FancyPacket packet, sf::TcpSocket* socket);
	void receiveData();
private:
	UdpHandler* _udpHandler;
	TcpHandler* _tcpHandler;

	std::list<std::pair<sf::Packet, sf::TcpSocket*>> tcpSerData;
	std::list<FancyPacket> _tcpUnserData;
	
	void receiveTcpData();
	void receiveUdpData();
	void distributeTcpData();

	virtual void notify(FancyPacket);
};

#endif