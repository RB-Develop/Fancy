#include "Player.h"

using namespace std;
using namespace sf;

Player::Player(string userName, string ipAddress, TcpSocket* tcpSocket, unsigned short udpPort)
{
	_userName = userName;
	_ipAddress = ipAddress;
	_tcpSocket = tcpSocket;
	_udpPort = udpPort;
}

Player::~Player()
{
	_tcpSocket->disconnect();
	delete _tcpSocket;
}

std::string Player::getUserName()
{
	return _userName;
}

std::string Player::getIpAddress()
{
	return _ipAddress;
}

unsigned short Player::getTeam()
{
	return _team;
}

void Player::setTeam(unsigned short team)
{
	_team = team;
}

sf::TcpSocket* Player::getTcpSocket()
{
	return _tcpSocket;
}

unsigned short Player::getUdpPort()
{
	return _udpPort;
}