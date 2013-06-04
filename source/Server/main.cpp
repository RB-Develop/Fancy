#include "Server.h"
#include "TcpHandler.h"
#include "UdpHandler.h"
#include "PacketHandler.h"

#include <SFML/System.hpp>

void acceptNewClients(TcpHandler* tcp)
{
	while(true) 
		tcp->acceptConnections();
}

int main()
{	
	TcpHandler* tcpHandler = new TcpHandler();
	UdpHandler* udpHandler = new UdpHandler();

	PacketHandler* packetHandler = new PacketHandler(udpHandler, tcpHandler);

	Server* server = new Server(packetHandler);

	packetHandler->attach(server);

	sf::Thread acceptThread(&acceptNewClients, tcpHandler);

	acceptThread.launch();

	while(true)
	{
		tcpHandler->keepSocketsAlive();
		packetHandler->receiveData();
		server->run();
	}

	return 0;
}