#include "PacketHandler.h"

using namespace sf;

PacketHandler::PacketHandler()
{		
	recipient = "localhost";

	// bind the socket to a port
	if (socket.bind(54001) != Socket::Done)
	{
		printf("Cannot bind the socket [Client]\n");
	}	
}

PacketHandler::~PacketHandler()
{

}

void PacketHandler::sendPacket(unsigned int request, std::string userName)
{
	char packet_data[packet_size];
	packet.packet_type = request;
	packet.userName = userName;

	packet.serialize(packet_data);

	unsigned short port = 54000;
	
	if (socket.send(packet_data, 100, recipient, port) != Socket::Done)
	{
		printf("error sending message [Client]\n");
	}
}