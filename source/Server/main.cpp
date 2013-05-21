#include <NetworkData.h>

#include "PacketReceiver.h"
#include "PlayerData.h"
#include "WorldData.h"
#include "LobbyData.h"

int main()
{	
	PacketReceiver receiver;

	Observer* playerData = new PlayerData(&receiver);
	playerData->setInterest(PacketTypes::REQUEST_REGISTER_PLAYER);

	Observer* lobbyData = new LobbyData(&receiver);
	lobbyData->addInterest(PacketTypes::REQUEST_LOBBY_LIST);
	lobbyData->addInterest(PacketTypes::REQUEST_NEW_LOBBY);
	lobbyData->addInterest(PacketTypes::REQUEST_JOIN_LOBBY);

	Observer* worldData = new WorldData(&receiver);
	worldData->setInterest(PacketTypes::ACTION_EVENT);
	
	while(true)
	{
		receiver.run();
	}

	return 0;
}