#ifndef FANCY_PLAYER_DATA
#define FANCY_PLAYER_DATA

#include <list>

#include <NetworkData.h>

#include "Player.h"

class PlayerData
{
public:
	PlayerData();
	virtual ~PlayerData();

	
	void addPlayer(Player*);
	void removePlayer(sf::TcpSocket* playerSocket);
	
	bool playerExists(std::string playerName);
private:
	std::list<Player*> players;

	FancyPacket _response;
	const FancyPacket _nullPacket;	
};

#endif 