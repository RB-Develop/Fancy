#include "Networker.h"

using namespace std;
using namespace sf;

Networker::Networker()
{
	if (_socket.bind(54000) != Socket::Done)
	{
		printf("Failed to bind socket");
	}
	_data = "";
}

bool Networker::sendPacket(const char* packet_data, const unsigned int packet_size, const char* clientAdress, const unsigned int clientPort)
{
	if (_socket.send(packet_data, packet_size, clientAdress, clientPort) != Socket::Done)
	{
		printf("Can't send");
		return false;
	}
	return true;
}