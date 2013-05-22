#include "PacketReceiver.h"

using namespace sf;

PacketReceiver::PacketReceiver()
{
	_socketUdp.setBlocking(false);

	// bind the socket to a port
	if (_socketUdp.bind(54000) != sf::Socket::Done)
	{
		printf("Cannot bind the UDP socket [Server]\n");
	}

	if (_tcpListener.listen(53000) != sf::Socket::Done)
	{
		printf("Cannot bind the TCP socket [Server]\n");
	}
	startTime = clock();
	secondsPassed = 0;
}

PacketReceiver::~PacketReceiver()
{
}

void PacketReceiver::run()
{
	monitorTcpClients();
}

void PacketReceiver::receiveUdp()
{
	_socketUdp.receive(_serializedPacketUdp, sender, port);

	if(_serializedPacketUdp.getDataSize() <= 0)
		return;

	_serializedPacketUdp >> _packetUdp;

	notify();
}

void PacketReceiver::receiveTcp()
{
	_socketUdp.receive(_serializedPacketUdp, sender, port);

	if(_serializedPacketUdp.getDataSize() <= 0)
		return;

	_serializedPacketUdp >> _packetUdp;

	notify();
}

void PacketReceiver::acceptNewConnections()
{
	sf::TcpSocket* client = new sf::TcpSocket();
	client->setBlocking(false);

	if (_tcpListener.accept(*client) != sf::Socket::Done)
	{
		printf("Listening failed. \n");
		return;
	}
	std::cout<<client->getRemotePort();
	_mutex.lock();
	_connectedClients.push_back(client);
	_mutex.unlock();
}

void PacketReceiver::monitorTcpClients()
{
	secondsPassed = (float)(clock() - startTime)/CLOCKS_PER_SEC;	
	if(secondsPassed >= 1)
	{
		_mutex.lock();
		for(std::list<sf::TcpSocket*>::iterator it = _connectedClients.begin(); it != _connectedClients.end(); it++)
		{
			if((*it)->send(" ", 1) == sf::Socket::Disconnected)
			{
				notifyClientDisconnect((*it)->getRemoteAddress().toString());
				delete *it;
			}
		}
		_mutex.unlock();
		startTime = clock();
	}
}

FancyPacket* PacketReceiver::getPacketUdp()
{
	return &_packetUdp;
}

FancyPacket* PacketReceiver::getPacketTcp()
{
	return &_packetTcp;
}

IpAddress* PacketReceiver::getSender()
{
	return &sender;
}

unsigned short PacketReceiver::getSenderPort()
{
	return port;
}

void PacketReceiver::respond(Packet* packet, IpAddress* address, unsigned short clientPort)
{
	if(_socketUdp.send(*packet, *address, clientPort) != Socket::Done)
	{
		printf("Can't send.\n");
	}
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

void PacketReceiver::respond(const char* packet_data, const unsigned int packet_size, IpAddress* clientAdress, const unsigned short clientPort)
{
if (_socket.send(packet_data, packet_size, *clientAdress, clientPort) != Socket::Done)
{
printf("Can't send.\n");
}
}
*/