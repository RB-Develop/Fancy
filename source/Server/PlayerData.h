#ifndef FANCY_PLAYER_DATA
#define FANCY_PLAYER_DATA

#include <list>

#include <NetworkData.h>

class PlayerData
{
public:
	PlayerData();
	virtual ~PlayerData();

	virtual void update();
private:
	std::list<PlayerPacket> players;

	sf::Packet _serializedPacket;
	FancyPacket _response;
	const FancyPacket _nullPacket;

	void handleRegisterRequest();
	bool playerExists(std::string playerName);

	void responseFailure();
	void responseSucces();
	void broadCastPlayerList();
	void addNewPlayer();
};

#endif 