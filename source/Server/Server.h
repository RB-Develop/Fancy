#ifndef FANCY_SERVER
#define FANCY_SERVER

#include "Observer.h"

#include "PacketHandler.h"
#include "PlayerData.h"
#include "WorldData.h"
#include "GameLobbyData.h"

class Server : public Observer
{
public:
	Server(PacketHandler*);
	~Server();

	void run();

	virtual void update(FancyPacket packet);
private:
	PlayerData* _playerData;
	GameLobbyData* _gameLobbyData;

	PacketHandler* _packetHandler;

	FancyPacket _responsePacket;
};

#endif