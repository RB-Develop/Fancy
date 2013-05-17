#ifndef FANCY_WORLD_DATA
#define FANCY_WORLD_DATA

#include <set>

#include "Observer.h"
#include "Subject.h"
#include "PacketReceiver.h"

class WorldData : public Observer
{
public:
	WorldData(PacketReceiver*);
	virtual ~WorldData();

	virtual void update(Subject*);
private:
	PacketReceiver* _subject;
};

#endif 