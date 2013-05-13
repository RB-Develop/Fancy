#ifndef	FANCY_NETWORKER
#define FANCY_NETWORKER

#include <SFML/Network.hpp>
#include <Engine/PacketHandler.h>

namespace fancy {
	namespace network {
	
		class Networker
		{		
		public:
			static Networker* instance();
						
			void setHostIp(std::string hostAdress);

			bool openUdpSocket(unsigned short port);
			bool sendPacket(const char* data, const unsigned int packet_size);

			char* receiveData();
		protected:
			Networker();
		private:
			static Networker* _instance;
			
			char* _data;
			unsigned short _hostPort;

			sf::IpAddress _hostAdress;
			sf::UdpSocket _socket;
			
			std::size_t _receivedSize;
		};

	}
}

#endif