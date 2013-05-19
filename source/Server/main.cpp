#include <NetworkData.h>

#include "PacketReceiver.h"
#include "PlayerData.h"
#include "WorldData.h"

int main()
{	
	PacketReceiver receiver;
	Observer* playerData = new PlayerData(&receiver);
	playerData->setInterest(PacketTypes::REGISTER_PLAYER);
	Observer* worldData = new WorldData(&receiver);
	worldData->setInterest(PacketTypes::ACTION_EVENT);
	
	while(true)
	{
		receiver.run();
	}

	return 0;
}