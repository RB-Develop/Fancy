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
	if(changedSubject != _subject)
		return;

	if(isOfInterest(_subject->getPacket()) == false)
		return;

	std::string userName = _subject->getPacket()->userName.c_str();

	FancyPacket response;
	response.userName = "Server";
	response.packet_type = PacketTypes::REGISTER_SUCCES;

	char responseData[MAX_PACKET_SIZE];
	response.serialize(responseData);

	if(players.find(userName) != players.end()) {
		printf("Player already exists. Respond with a failure to subscribe.\n");
	}
	else {
		printf("New player, adding to the existing set and respond with a success message.\n");
		_subject->respond(responseData, sizeof(FancyPacket), _subject->getSender(), _subject->getSenderPort());
		players.insert(userName);
	}
}