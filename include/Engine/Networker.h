#ifndef	FANCY_NETWORKER
#define FANCY_NETWORKER

#include <SFML/Network.hpp>
#include <Engine/PacketHandler.h>

namespace fancy {
	namespace network {
	
		class Networker
		{		
		public:		
			Networker();
			void setHostIp(std::string hostAdress);

			bool openUdpSocket(unsigned short port);
			bool sendPacket(sf::Packet* packet);

			sf::Packet* receiveData();
		private:						
			unsigned short _hostPort;
			sf::IpAddress _hostAdress;
			sf::UdpSocket _socket;
			
			unsigned short _receivedFromPort;
			sf::IpAddress _receivedFromAdress;

			sf::Packet _receivedPacket;
		};

	}
}

#endif