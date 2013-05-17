#ifndef	FANCY_SERVER_NETWORKER
#define FANCY_SERVER_NETWORKER

#include <SFML/Network.hpp>
#include <NetworkData.h>

class Networker
{		
public:	
	Networker();

	bool sendPacket(const char* packet_data, const unsigned int packet_size, const char* clientAdress, const unsigned int clientPort);
private:			
	char* _data;

	sf::UdpSocket _socket;
};

#endif