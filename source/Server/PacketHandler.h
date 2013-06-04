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
	
	void sendData(FancyPacket packet, std::string ipAddress, unsigned int protocol, unsigned short port);
	void receiveData();
private:
	UdpHandler* _udpHandler;
	TcpHandler* _tcpHandler;

	void receiveTcpData();
	void receiveUdpData();

	virtual void notify(FancyPacket);
};

#endif