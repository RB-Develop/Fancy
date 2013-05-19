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
		port = _socket.AnyPort;

	if (_socket.bind(port) != Socket::Done)
	{
		return false;
	}	
	_socket.setBlocking(false);
	printf("UDP socket set up on port %i.\n", port);
	return true;
}

bool Networker::sendPacket(Packet* packet)
{
	if (_socket.send(*packet, _hostAdress, _hostPort) != Socket::Done)
	{
		printf("Can't send");
		return false;
	}
	return true;
}

Packet* Networker::receiveData()
{
	_socket.receive(_receivedPacket, _receivedFromAdress, _receivedFromPort);

	if(_receivedPacket.getDataSize() <= 0)
		return NULL;

	if(_receivedFromAdress != _hostAdress && _receivedFromPort != _hostPort) {
		printf("Packet injection detected, cheater on the loose. \n");
		return NULL;
	}
	
	return &_receivedPacket;
}

/*char* Networker::receiveData()
{
	_socket.receive(_data, 1000, _receivedSize, _receivedFromAdress, _receivedFromPort);

	if(_receivedSize <= 0)
		return NULL;

	if(_receivedFromAdress != _hostAdress && _receivedFromPort != _hostPort) {
		printf("Packet injection detected, cheater on the loose. \n");
		return NULL;
	}
	
	return _data;
}*/