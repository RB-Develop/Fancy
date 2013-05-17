#ifndef FANCY_PLAYER_DATA
#define FANCY_PLAYER_DATA

#include <set>

#include "Observer.h"
#include "Subject.h"
#include "PacketReceiver.h"

class PlayerData : public Observer
{
public:
	PlayerData(PacketReceiver*);
	virtual ~PlayerData();

	virtual void update(Subject*);
private:
	PacketReceiver* _subject;
	std::set<std::string> players;
};

#endif 