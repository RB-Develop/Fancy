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

			bool openUdpSocket(unsigned short port);

			bool registerUsername(char* username);
			char* receiveOnSocket();
		protected:
			Networker();
		private:
			static Networker* _instance;
			static PacketHandler* _packetHandler;

			const char* _username;

			sf::IpAddress _hostAddress;
			sf::UdpSocket _socket;
		};

	}
}

#endif