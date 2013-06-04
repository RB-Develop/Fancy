#ifndef FANCY_PLAYER
#define FANCY_PLAYER

#include <SFML/Network.hpp>

class Player
{
public:
	Player(std::string, std::string, sf::TcpSocket*, unsigned short);
	~Player();

	std::string getUserName();
	
	std::string getIpAddress();

	unsigned short getTeam();
	void setTeam(unsigned short team);

	sf::TcpSocket* getTcpSocket();

	unsigned short getUdpPort();
private:
	std::string _userName;
	std::string _ipAddress;
	unsigned short _team;

	sf::TcpSocket* _tcpSocket;
	unsigned short _udpPort;
};

#endif