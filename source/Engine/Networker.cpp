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
		break;
	case PROTOCOL_TCP:
		return sendTcp(packet);
		break;
	}
	return false;
}

bool Networker::sendUdp(Packet* packet)
{
	if (_socketUdp.send(*packet, _hostAdress, _hostPort) != Socket::Done)
	{
		printf("Can't send");
		return false;
	}
	return true;
}

bool Networker::sendTcp(Packet* packet)
{
	if (_socketTcp.send(*packet) != Socket::Done)
	{
		printf("Can't send");
		return false;
	}
	return true;
}

Packet* Networker::receiveDataUdp()
{
	_socketUdp.receive(_receivedPacketUdp, _receivedFromAdress, _receivedFromPort);

	if(_receivedPacketUdp.getDataSize() <= 0)
		return NULL;

	if(_receivedFromAdress != _hostAdress && _receivedFromPort != _hostPort) {
		printf("Packet injection detected, cheater on the loose. \n");
		return NULL;
	}
	
	return &_receivedPacketUdp;
}

Packet* Networker::receiveDataTcp()
{
	_socketTcp.receive(_receivedPacketTcp);

	if(_receivedPacketTcp.getDataSize() <= 0)
		return NULL;
	
	return &_receivedPacketTcp;
}