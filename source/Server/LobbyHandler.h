#ifndef FANCY_LOBBY_HANDLER
#define FANCY_LOBBY_HANDLER

#include <iostream>
#include <list>
#include <string>

#include <NetworkData.h>
#include <SFML/Network.hpp>

class LobbyHandler
{
private:
	std::list<Lobby> _lobbies;
public:
	LobbyHandler();
	~LobbyHandler();

	void createNewLobby(const std::string lobbyName);
	void removeLobby(const std::string lobbyName);
};

#endif