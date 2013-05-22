#include "LobbyData.h"

using namespace std;

LobbyData::LobbyData(PacketReceiver* observeSubject) : _nullPacket()
{
	_subject = observeSubject;
	_subject->attach(this);
}

LobbyData::~LobbyData()
{
	_subject->detach(this);
}

void LobbyData::update(Subject* changedSubject)
{
	if(changedSubject != _subject ||
		isOfInterest(_subject->getPacketUdp()) == false)
	{
		return;
	}

	printf("Works \n");
}

void LobbyData::handleClientDisconnect(string ipAdress)
{
}

void LobbyData::createNewLobby(string lobbyName)
{
}