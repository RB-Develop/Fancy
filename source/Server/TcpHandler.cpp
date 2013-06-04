#include "TcpHandler.h"

using namespace sf;
using namespace std;

TcpHandler::TcpHandler() : _portRange(10)
{
	_currentListenerPort = 53000;
	_startListenerPort = 53000;
	_maxListenerPort = _startListenerPort + _portRange;

	rebind(_currentListenerPort);

	startTime = clock();
	secondsPassed = 0;

	_nullPacket = new Packet();
}

TcpHandler::~TcpHandler()
{
}

void TcpHandler::rebind(unsigned short newPort)
{
	if (_listener.listen(_currentListenerPort) != sf::Socket::Done)
	{
		printf("Cannot bind the TCP socket [Server]\n");
	}
}

void TcpHandler::acceptConnections()
{
	TcpSocket* client = new TcpSocket();

	if (_listener.accept(*client) != Socket::Done)
	{
		printf("Listening failed. \n");
		return;
	}

	printf("New connection on port: ");
	client->setBlocking(false);

	std::cout<<client->getLocalPort()<<std::endl;
	_mutex.lock();
	_connectedClients.push_back(client);
	_mutex.unlock();
}

TcpSocket* TcpHandler::keepSocketsAlive()
{
	_deadSocket = NULL;
	secondsPassed = (float)(clock() - startTime)/CLOCKS_PER_SEC;	

	if(secondsPassed >= 1)
	{		
		_mutex.lock();
		for(list<TcpSocket*>::iterator it = _connectedClients.begin(); it != _connectedClients.end(); it++)
		{
			if((*it)->send("", 1) == sf::Socket::Disconnected)
			{
				printf("Player left\n");
				_deadSocket = *it;
				_connectedClients.remove(*it);
				break;
			}
		}
		_mutex.unlock();
		startTime = clock();
	}

	return _deadSocket;
}

list<pair<Packet, TcpSocket*>> TcpHandler::receiveData()
{
	_mutex.lock();

	_serializedPackets.clear();

	for(list<TcpSocket*>::iterator it = _connectedClients.begin(); it != _connectedClients.end(); it++)
	{
		char data[100];
		size_t size;

		(*it)->receive(data, 100, size);

		tempPacket.append(data, size);

		if(size > 4) { 
			_serializedPackets.push_back(pair<Packet, TcpSocket*>(tempPacket, (*it)));
		}

		tempPacket.clear();
	}

	_mutex.unlock();
	return _serializedPackets;
}

void TcpHandler::broadcastData(Packet* packet)
{
	_mutex.lock();
	for(list<TcpSocket*>::iterator it = _connectedClients.begin(); it != _connectedClients.end(); it++)
	{
		if((*it)->send(packet->getData(), sizeof(*packet)) != Socket::Done)
		{
			printf("Can't send.\n");
		}
	}
	_mutex.unlock();
}

void TcpHandler::sendData(Packet* packet, TcpSocket* recipient)
{
	_mutex.lock();

	if(recipient->send(packet->getData(), sizeof(*packet)) != Socket::Done)
	{
		std::cout << "Can't send TCP on this port: " << recipient->getLocalPort() << ". To this port: " << recipient->getRemotePort() << std::endl;
	}

	_mutex.unlock();
}