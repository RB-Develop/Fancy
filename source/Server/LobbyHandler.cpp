#include "LobbyHandler.h"

LobbyHandler::LobbyHandler()
{
}

LobbyHandler::~LobbyHandler()
{
}

void LobbyHandler::createNewLobby(std::string lobbyName)
{
	Lobby lobby;
	_lobbies.insert(std::pair<std::string, Lobby>(lobbyName, lobby));
	std::cout<<"Making new lobby: " << lobbyName << "\n";
}