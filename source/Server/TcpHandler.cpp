#include "TcpHandler.h"

using namespace sf;
using namespace std;

TcpHandler::TcpHandler()
{
	if (_listener.listen(53000) != sf::Socket::Done)
	{
		printf("Cannot bind the TCP socket [Server]\n");
	}
	startTime = clock();
	secondsPassed = 0;
}

TcpHandler::~TcpHandler()
{
}

void TcpHandler::acceptConnections()
{
	TcpSocket* client = new TcpSocket();
	client->setBlocking(false);

	if (_listener.accept(*client) != Socket::Done)
	{
		printf("Listening failed. \n");
		return;
	}

	_mutex.lock();
	_connectedClients.push_back(client);
	_mutex.unlock();
}

void TcpHandler::keepSocketsAlive()
{
	secondsPassed = (float)(clock() - startTime)/CLOCKS_PER_SEC;	
	if(secondsPassed >= 1)
	{
		_mutex.lock();
		for(list<sf::TcpSocket*>::iterator it = _connectedClients.begin(); it != _connectedClients.end(); it++)
		{
			if((*it)->send(" ", 1) == sf::Socket::Disconnected)
			{
				delete *it;
			}
		}
		_mutex.unlock();
		startTime = clock();
	}
}

FancyPacket TcpHandler::receiveData()
{
	_mutex.lock();

	Packet serializedPacket;
	FancyPacket packet;

	for(list<sf::TcpSocket*>::iterator it = _connectedClients.begin(); it != _connectedClients.end(); it++)
	{
		(*it)->receive(serializedPacket);

		if(serializedPacket.getDataSize() <= 0)
		{
			serializedPacket >> packet;
			_mutex.unlock();
			return packet;
		}
	}

	_mutex.unlock();
}

void TcpHandler::sendData(Packet* packet, string recipient)
{
	_mutex.lock();
	for(list<sf::TcpSocket*>::iterator it = _connectedClients.begin(); it != _connectedClients.end(); it++)
	{
		if((*it)->getRemoteAddress().toString() == recipient)
		{
			if((*it)->send(*packet) != Socket::Done)
			{
				printf("Can't send.\n");
			}
		}
	}
	_mutex.unlock();
}