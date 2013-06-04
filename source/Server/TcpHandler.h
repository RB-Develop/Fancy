#ifndef FANCY_TCP_HANDLER
#define FANCY_TCP_HANDLER

#include <iostream>
#include <list>
#include <windows.h>
#include <ctime>
#include <cstdlib>

#include <SFML/Network.hpp>
#include <NetworkData.h>

class TcpHandler
{
public:
	TcpHandler();
	~TcpHandler();

	void acceptConnections();
	void keepSocketsAlive();

	std::list<sf::Packet> receiveData();
	void sendData(sf::Packet* packet, std::string recipient);
protected:
private:
	sf::Mutex _mutex;
	clock_t startTime;
	float secondsPassed;

	sf::Packet* _nullPacket;
	std::list<sf::Packet> _serializedPackets;

	sf::Packet tempPacket;
	sf::TcpListener _listener;
	std::list<sf::TcpSocket*> _connectedClients;	
};

#endif