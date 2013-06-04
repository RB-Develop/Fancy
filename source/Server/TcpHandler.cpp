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

	_nullPacket = new Packet();
}

TcpHandler::~TcpHandler()
{
}

void TcpHandler::acceptConnections()
{
	TcpSocket* client = new TcpSocket();

	if (_listener.accept(*client) != Socket::Done)
	{
		printf("Listening failed. \n");
		return;
	}

	client->setBlocking(false);

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
		for(list<TcpSocket*>::iterator it = _connectedClients.begin(); it != _connectedClients.end(); it++)
		{
			if((*it)->send("", 1) == sf::Socket::Disconnected)
			{
				printf("Player left");
				delete *it;
			}
		}
		_mutex.unlock();
		startTime = clock();
	}
}

list<Packet> TcpHandler::receiveData()
{
	_mutex.lock();

	_serializedPackets.clear();

	for(list<TcpSocket*>::iterator it = _connectedClients.begin(); it != _connectedClients.end(); it++)
	{
		(*it)->receive(tempPacket);

		if(tempPacket.getDataSize() > 0) { 
			// Hack for abtraction.
			FancyPacket tempExtracted;
			tempPacket>>tempExtracted;

			tempExtracted.ipAdress = (*it)->getRemoteAddress().toString();
			tempExtracted.tcpSocket = (*it);

			tempPacket<<tempExtracted;
			// End of hack, that wasn't so bad!
			_serializedPackets.push_back(tempPacket);
		}
	}

	_mutex.unlock();
	return _serializedPackets;
}

void TcpHandler::sendData(Packet* packet, string recipient)
{
	_mutex.lock();
	for(list<TcpSocket*>::iterator it = _connectedClients.begin(); it != _connectedClients.end(); it++)
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