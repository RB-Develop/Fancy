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
	
}