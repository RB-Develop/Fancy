#ifndef FANCY_LOBBY_DATA
#define FANCY_LOBBY_DATA

#include <list>

#include "Observer.h"
#include "Subject.h"
#include "PacketReceiver.h"
#include <NetworkData.h>

class LobbyData : public Observer
{
public:
	LobbyData(PacketReceiver* observeSubject);
	virtual ~LobbyData();

	virtual void update(Subject* subject);	
	virtual void handleClientDisconnect(std::string ipAdress);
private:
	PacketReceiver* _subject;

	sf::Packet _serializedPacket;
	FancyPacket _response;
	const FancyPacket _nullPacket;

	void createNewLobby(const std::string lobbyName);
	void removeLobby(const std::string lobbyName);
};

#endif