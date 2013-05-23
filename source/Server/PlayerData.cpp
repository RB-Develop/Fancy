#include "PlayerData.h"

using namespace std;

PlayerData::PlayerData()
{
}

PlayerData::~PlayerData()
{
}

void PlayerData::update()
{
}

void PlayerData::handleRegisterRequest()
{
	addNewPlayer();
	responseSucces();
}

void PlayerData::responseFailure()
{
}

void PlayerData::responseSucces()
{
}

bool PlayerData::playerExists(string playerName)
{
	for(list<PlayerPacket>::iterator i=players.begin(); i!=players.end(); ++i)
	{
		if((*i).userName == playerName) {
			return true;
		}
	}
	return false;
}

void PlayerData::addNewPlayer()
{
}