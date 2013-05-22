#ifndef FANCY_PACKET_RECEIVER
#define FANCY_PACKET_RECEIVER

#include <iostream>
#include <list>
#include <windows.h>
#include <ctime>
#include <cstdlib>

#include <SFML/Network.hpp>
#include <NetworkData.h>

#include "Subject.h"

class PacketReceiver : public Subject
{
public:
	PacketReceiver();
	virtual ~PacketReceiver();

	void run();
	void receiveUdp();
	void receiveTcp();

	void acceptNewConnections();
	void monitorTcpClients();

	void respond(sf::Packet*, sf::IpAddress*, const unsigned short clientPort);
	
	FancyPacket* getPacketUdp();
	FancyPacket* getPacketTcp();
	sf::IpAddress* getSender();
	unsigned short getSenderPort();
private:
	sf::Mutex _mutex;
	clock_t startTime;
	float secondsPassed;

	unsigned short port;

	sf::UdpSocket _socketUdp;

	sf::IpAddress sender;
	sf::Packet _serializedPacketUdp;
	sf::Packet _serializedPacketTcp;

	FancyPacket _packetUdp;
	FancyPacket _packetTcp;

	sf::TcpListener _tcpListener;
	std::list<sf::TcpSocket*> _connectedClients;	
};

#endif