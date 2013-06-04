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

	void rebind(unsigned short);
	void acceptConnections();

	/*
	This function keeps all the TCP socket alive.
	*/
	sf::TcpSocket* keepSocketsAlive();

	std::list<std::pair<sf::Packet, sf::TcpSocket*>> receiveData();

	void broadcastData(sf::Packet*);
	void sendData(sf::Packet*, sf::TcpSocket*);
protected:
private:
	sf::Mutex _mutex;
	clock_t startTime;
	float secondsPassed;

	sf::Packet* _nullPacket;
	std::list<std::pair<sf::Packet, sf::TcpSocket*>> _serializedPackets;

	sf::Packet tempPacket;
	sf::TcpListener _listener;
	sf::TcpSocket* _deadSocket;

	std::list<sf::TcpSocket*> _connectedClients;

	unsigned short _currentListenerPort, _startListenerPort, _maxListenerPort;
	const unsigned short _portRange;
};

#endif