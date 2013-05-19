#ifndef FANCY_PLAYER_DATA
#define FANCY_PLAYER_DATA

#include <list>

#include "Observer.h"
#include "Subject.h"
#include "PacketReceiver.h"
#include <NetworkData.h>

class PlayerData : public Observer
{
public:
	PlayerData(PacketReceiver*);
	virtual ~PlayerData();

	virtual void update(Subject*);
private:
	PacketReceiver* _subject;
	std::list<PlayerPacket> players;

	sf::Packet _serializedPacket;
	FancyPacket _response;
	const FancyPacket _nullPacket;
};

#endif 