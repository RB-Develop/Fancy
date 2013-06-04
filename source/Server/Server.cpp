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

void Server::update(FancyPacket packet)
{
	if(packet.packet_type == REQUEST_REGISTER_PLAYER)
	{
		Player* newPlayer = new Player(packet.userName, packet.ipAdress, packet.tcpSocket, packet.port);

		_responsePacket = *_playerData->addPlayer(newPlayer);
		_packetHandler->sendData(_responsePacket, packet.ipAdress, PROTOCOL_TCP, 0);
	}
	printf("Got data \n");
}