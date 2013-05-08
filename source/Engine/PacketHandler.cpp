#include <Engine/PacketHandler.h>

using namespace sf;
using namespace std;

using namespace fancy;
using namespace fancy::network;

PacketHandler::PacketHandler(string hostAdress)
{		
	_hostAddress = hostAdress;

	// bind the socket to a port
	if (_socket.bind(54001) != Socket::Done)
	{
		printf("Error binding the specified socket.\n");
	}	
}

PacketHandler::~PacketHandler()
{

}

void PacketHandler::sendPacket(const char* packet_data, const unsigned int packet_size)
{
	unsigned short port = 54000;
	
	if (_socket.send(packet_data, packet_size, _hostAddress, port) != Socket::Done)
	{
		printf("Error sending message to the server.\n");
	}
}