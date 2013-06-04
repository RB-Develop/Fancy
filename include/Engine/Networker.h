#ifndef	FANCY_NETWORKER
#define FANCY_NETWORKER

#include <list>
#include <SFML/Network.hpp>

namespace fancy {
	namespace network {	
		class Networker
		{		
		public:		
			Networker();
			~Networker();

			void setHostIp(std::string hostAdress);

			bool openUdpSocket(unsigned short port);
			bool openTcpSocket(unsigned short port);

			/*
			* Class for sending packets using UDP or TCP.
			*
			* @param packet
			* The packet to send.
			* @param protocol
			* The parameter defining how the packet should be send; 0 is UDP, 1 is TCP.
			*/
			bool sendPacket(sf::Packet* packet, unsigned int protocol = PROTOCOL_UDP);

			sf::Packet* receiveDataUdp();
			sf::Packet receiveDataTcp();
		private:		
			enum Protocol
			{
				PROTOCOL_UDP = 0,
				PROTOCOL_TCP
			};

			unsigned short _hostPort;
			sf::IpAddress _hostAdress;

			sf::UdpSocket _socketUdp;
			sf::TcpSocket _socketTcp;

			sf::Packet _receivedPacketUdp;
			unsigned short _receivedFromPort;
			sf::IpAddress _receivedFromAdress;

			sf::Mutex _lock;

			std::list<sf::Packet> _packets;

			bool sendUdp(sf::Packet* packet);
			bool sendTcp(sf::Packet* packet);
		};

	}
}

#endif