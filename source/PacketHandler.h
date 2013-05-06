#ifndef FANCY_PACKET_HANDLER
#define FANCY_PACKET_HANDLER

#include <SFML/Network.hpp>
#include <NetworkData.h>

class PacketHandler 
{
private:
	static const unsigned int packet_size = sizeof(FancyPacket);

	sf::IpAddress recipient;
	sf::UdpSocket socket;

	FancyPacket packet;
public:
	PacketHandler();
	~PacketHandler();

	void sendPacket(unsigned int request, std::string userName);
};

#endif