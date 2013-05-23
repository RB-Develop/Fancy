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
	Server* server = new Server();
	TcpHandler* tcpHandler = new TcpHandler();
	UdpHandler* udpHandler = new UdpHandler();

	PacketHandler* packetHandler = new PacketHandler(udpHandler, tcpHandler);
	packetHandler->attach(server);

	sf::Thread acceptThread(&acceptNewClients, tcpHandler);

	acceptThread.launch();

	while(true)
	{
		packetHandler->receiveData();
		server->run();
	}

	return 0;
}