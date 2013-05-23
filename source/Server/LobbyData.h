#ifndef FANCY_LOBBY_DATA
#define FANCY_LOBBY_DATA

#include <list>

#include <NetworkData.h>

class LobbyData
{
public:
	LobbyData();
	virtual ~LobbyData();

	virtual void update();	
private:
	void createNewLobby(const std::string lobbyName);
	void removeLobby(const std::string lobbyName);
};

#endif