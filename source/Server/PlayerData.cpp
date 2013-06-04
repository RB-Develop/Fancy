#include "PlayerData.h"

using namespace std;

PlayerData::PlayerData() : _nullPacket()
{

}

PlayerData::~PlayerData()
{

}

void PlayerData::addPlayer(Player* player)
{
	players.push_back(player);
}

void PlayerData::removePlayer(sf::TcpSocket* playerSocket)
{
	for(list<Player*>::iterator i=players.begin(); i!=players.end(); ++i)
	{
		if((*i)->getTcpSocket() == playerSocket) {
			delete *i;
			players.remove(*i);
			return;
		}
	}
	playerSocket->disconnect();
	delete playerSocket;
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