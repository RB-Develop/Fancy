#include "PlayerData.h"

using namespace std;

PlayerData::PlayerData() : _nullPacket()
{

}

PlayerData::~PlayerData()
{

}

FancyPacket* PlayerData::addPlayer(Player* player)
{
	FancyPacket* response = new FancyPacket;

	if(playerExists(player->getUserName()))
	{
		response->packet_type = REGISTER_FAIL;
		return response;
	}

	response->packet_type = REGISTER_SUCCES;
	return response;
}

bool PlayerData::playerExists(string playerName)
{
	for(list<Player*>::iterator i=players.begin(); i!=players.end(); ++i)
	{
		if((*i)->getUserName() == playerName) {
			return true;
		}
	}
	return false;
}