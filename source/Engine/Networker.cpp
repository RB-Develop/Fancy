#include <Engine/Networker.h>

#include <iostream>

using namespace std;
using namespace sf;
using namespace fancy::network;

Networker::Networker()
{
	_hostPort = _receivedFromPort = 54000;
	_hostAdress = _receivedFromAdress = "localhost";
}

Networker::~Networker()
{
	_socketTcp.disconnect();
}

void Networker::setHostIp(string hostAdress)
{
	_hostAdress = hostAdress;
}

bool Networker::openUdpSocket(unsigned short port)
{
	if(port == 0)
		port = _socketUdp.AnyPort;

	if (_socketUdp.bind(port) != Socket::Done)
	{
		return false;
	}

	_socketUdp.setBlocking(false);
	printf("UDP socket set up on port %i.\n", _socketUdp.getLocalPort());
	return true;
}

bool Networker::openTcpSocket(unsigned short port)
{
	if(port == 0)
		port = _socketTcp.AnyPort;

	if(_socketTcp.connect(_hostAdress, port) != Socket::Done)
	{
		printf("Cannot connect to host [TCP].\n");
		return false;
	}

	_socketTcp.setBlocking(false);
	printf("TCP socket set up on port %i.\n", _socketTcp.getLocalPort());
	return true;
}

bool Networker::sendPacket(Packet* packet, unsigned int protocol)
{
	switch(protocol)
	{
	case PROTOCOL_UDP:
		return sendUdp(packet);
	case PROTOCOL_TCP:
		return sendTcp(packet);
	}
	return false;
}

bool Networker::sendUdp(Packet* packet)
{
	_lock.lock();

	if (_socketUdp.send(*packet, _hostAdress, _hostPort) != Socket::Done)
	{
		printf("Can't send");
		_lock.unlock();
		return false;
	}

	_lock.unlock();
	return true;
}

bool Networker::sendTcp(Packet* packet)
{
	_lock.lock();

	if (_socketTcp.send(packet->getData(), sizeof(*packet)) != Socket::Done)
	{
		printf("Can't send");
		_lock.unlock();
		return false;
	}

	_lock.unlock();
	return true;
}

Packet* Networker::receiveDataUdp()
{
	_lock.lock();

	_socketUdp.receive(_receivedPacketUdp, _receivedFromAdress, _receivedFromPort);

	if(_receivedPacketUdp.getDataSize() <= 0)
	{
		_lock.unlock();
		return NULL;
	}

	if(_receivedFromAdress != _hostAdress && _receivedFromPort != _hostPort) {
		printf("Packet injection detected, cheater on the loose. \n");
		_lock.unlock();
		return NULL;
	}
	
	_lock.unlock();

	return &_receivedPacketUdp;
}

Packet Networker::receiveDataTcp()
{
	Packet _receivedPacketTcp = Packet();
	char data[100];
	size_t size;

	_lock.lock();
	
	_socketTcp.receive(data, 100, size);

	_receivedPacketTcp.append(data, size);

	_packets.push_back(_receivedPacketTcp);

	_lock.unlock();

	if(size > 4)
		return _receivedPacketTcp;

	_receivedPacketTcp.clear();
	return _receivedPacketTcp;
}