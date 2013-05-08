#ifndef FANCY_PACKET_HANDLER
#define FANCY_PACKET_HANDLER

#include <SFML/Network.hpp>

namespace fancy {
	namespace network {
		
		class PacketHandler 
		{
			friend class Networker;
		private:
			sf::IpAddress _hostAddress;
			sf::UdpSocket _socket;
			PacketHandler(std::string hostAdress);
		public:			
			~PacketHandler();

			void sendPacket(const char* packet_data, const unsigned int packet_size);
			char* receivePacket();
		};

	}
}
#endif