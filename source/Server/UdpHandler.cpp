#include "UdpHandler.h"

using namespace std;
using namespace sf;

UdpHandler::UdpHandler()
{
	_socket.setBlocking(false);

	if(_socket.bind(54000) != Socket::Done)
	{
		printf("Cannot bind the UDP socket [Server]\n");
	}
}

UdpHandler::~UdpHandler()
{
}

Packet* UdpHandler::receiveData()
{
	Packet* serializedPacket = new Packet();

	_socket.receive(*serializedPacket, _sender, _port);

	return serializedPacket;
}

IpAddress* UdpHandler::getSender()
{
	return &_sender;
}

unsigned short UdpHandler::getSenderPort()
{
	return _port;
}

void UdpHandler::sendData(Packet* packet, IpAddress* address, unsigned short clientPort)
{
	if(_socket.send(*packet, *address, clientPort) != Socket::Done)
	{
		printf("Can't send.\n");
	}
}