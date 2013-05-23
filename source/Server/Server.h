#ifndef FANCY_SERVER
#define FANCY_SERVER

#include "Observer.h"

#include "PlayerData.h"
#include "WorldData.h"
#include "LobbyData.h"

class Server : public Observer
{
public:
	Server();
	~Server();

	void run();

	virtual void update(FancyPacket packet);
private:
	PlayerData* _playerData;
	WorldData* _worldData;
	LobbyData* _lobbyData;
};

#endif