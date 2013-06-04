#include "Server.h"

Server::Server(PacketHandler* packetHandler)
{
	_playerData = new PlayerData();
	_gameLobbyData = new GameLobbyData();

	_packetHandler = packetHandler;
}

Server::~Server()
{
}

void Server::run()
{
}

void Server::handlePlayerDisconnect(sf::TcpSocket* disconnectedPlayer)
{
	_playerData->removePlayer(disconnectedPlayer);
}

void Server::update(FancyPacket packet)
{
	if(packet.packet_type == REQUEST_REGISTER_PLAYER)
	{
		if(_playerData->playerExists(packet.userName))
		{
			_responsePacket.packet_type = REGISTER_FAIL;
		}
		else
		{
			Player* newPlayer = new Player(packet.userName, packet.ipAdress, packet.tcpSocket, packet.port);
			_playerData->addPlayer(newPlayer);
			_responsePacket.packet_type = REGISTER_SUCCES;
		}

		_packetHandler->sendData(_responsePacket, packet.tcpSocket);
	}
	printf("Got data \n");
}