#include "PlayerData.h"

using namespace std;

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

	string userName = _subject->getPacket()->userName.c_str();

	for(list<PlayerPacket>::iterator i=players.begin(); i!=players.end(); ++i)
	{
		if((*i).userName == userName) {
			_response.packet_type = PacketTypes::REGISTER_FAIL;
			_serializedPacket << _response;
			_subject->respond(&_serializedPacket, _subject->getSender(), _subject->getSenderPort());

			_response = _nullPacket;
			_serializedPacket.clear();
			return;
		}
	}

	_response.packet_type = PacketTypes::REGISTER_SUCCES;

	PlayerPacket playerData; 
	playerData.userName = _subject->getPacket()->userName;
	playerData.ipAdress = _subject->getSender()->toString();
	playerData.port = _subject->getSenderPort();
	players.push_back(playerData);

	for(list<PlayerPacket>::iterator i=players.begin(); i!=players.end(); ++i)
	{
		_response.p_list.push_back(*i);
	}

	_serializedPacket << _response;

	for(list<PlayerPacket>::iterator i=players.begin(); i!=players.end(); ++i)
	{
		sf::IpAddress address((*i).ipAdress);
		_subject->respond(&_serializedPacket, &address, (*i).port);
	}

	_response = _nullPacket;
	_serializedPacket.clear();
}