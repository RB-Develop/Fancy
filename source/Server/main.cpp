#include <NetworkData.h>

#include "PacketReceiver.h"
#include "PlayerData.h"
#include "WorldData.h"
#include "LobbyData.h"

void acceptNewClients(PacketReceiver* receiver)
{
	while(true)
		receiver->acceptNewConnections();
}

int main()
{	
	PacketReceiver receiver;

	sf::Thread acceptThread(&acceptNewClients, &receiver);

	Observer* playerData = new PlayerData(&receiver);
	playerData->addInterest(PacketTypes::REQUEST_REGISTER_PLAYER);
	playerData->addInterest(PacketTypes::PLAYER_DISCONNECT);

	Observer* lobbyData = new LobbyData(&receiver);
	lobbyData->addInterest(PacketTypes::REQUEST_LOBBY_LIST);
	lobbyData->addInterest(PacketTypes::REQUEST_NEW_LOBBY);
	lobbyData->addInterest(PacketTypes::REQUEST_JOIN_LOBBY);

	Observer* worldData = new WorldData(&receiver);
	worldData->setInterest(PacketTypes::ACTION_EVENT);
	
	acceptThread.launch();

	while(true)
	{
		receiver.run();
	}

	return 0;
}