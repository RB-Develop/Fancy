#include "PlayerData.h"

PlayerData::PlayerData(PacketReceiver* observeSubject)
{
	_subject = observeSubject;
	_subject->attach(this);
}

PlayerData::~PlayerData()
{
	_subject->detach(this);
}

void PlayerData::update(Subject* changedSubject)
{
	if(_subject != changedSubject)
		return;

	if(isOfInterest(_subject->getPacket()) == false){
		printf("Can't be bothered, letting it slide. [Player Data] \n");
		return;
	}	
	printf("This is of interest to me! Working on it [Player Data] \n");

	std::string userName = _subject->getPacket()->userName.c_str();

	if(players.find(userName) != players.end()) {
		printf("Player already exists. Respond with a failure to subscribe.\n");
	}
	else {
		printf("New player, adding to the existing set and respond with a success message.\n");
		players.insert(userName);
	}

	delete &userName;
}

bool PlayerData::isOfInterest(FancyPacket* packet)
{
	if(packet->packet_type == PacketTypes::REGISTER_PLAYER)
		return true;
	return false;
}