#include "Server.h"

Server::Server()
{
	_playerData = new PlayerData();
	_lobbyData = new LobbyData();
	_worldData = new WorldData();
}

Server::~Server()
{
}

void Server::run()
{
}

void Server::update(FancyPacket packet)
{
	printf("Got data \n");
}