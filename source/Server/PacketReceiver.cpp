#include "PacketReceiver.h"

PacketReceiver::PacketReceiver(CallbackMediator* mediator) : _mediator(mediator)
{
	socket.setBlocking(false);

	// bind the socket to a port
	if (socket.bind(54000) != sf::Socket::Done)
	{
		printf("Cannot bind the socket [Server]\n");
	}
}

PacketReceiver::~PacketReceiver()
{
}

void PacketReceiver::run()
{
	socket.receive(network_data, 100, received, sender, port);

	if (received <= 0) 
	{
		//no data recieved
		return;
	}

	packet.deserialize(network_data);

	_mediator->handleRequest(packet.packet_type, sender.toString());

	Sleep(20);
}
/*
void PacketReceiver::receiveFromClients()
{
FancyPacket packet;

// go through all clients
std::map<unsigned int, SOCKET>::iterator iter;

for(iter = network->sessions.begin(); iter != network->sessions.end(); iter++)
{
// get data for that client
int data_length = network->receiveData(iter->first, network_data);

if (data_length <= 0) 
{
//no data recieved
continue;
}

int i = 0;
while (i < (unsigned int)data_length) 
{
packet.deserialize(&(network_data[i]));
i += sizeof(FancyPacket);

switch (packet.packet_type) {
case INIT_CONNECTION:
printf("server received init packet from client\n");
break;
case ACTION_EVENT:
printf("server received action event packet from client\n");
break;
default:
printf("error in packet types\n");
break;
}
}
}
}
*/