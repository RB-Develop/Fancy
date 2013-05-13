#include "CallbackObserver.h"

CallbackObserver::CallbackObserver()
{
	lobbyHandler = new LobbyHandler();
}

CallbackObserver::~CallbackObserver()
{
}

void CallbackObserver::handleRequest(unsigned int request, std::string sender)
{
	switch (request) {
	case INIT_CONNECTION:
		printf("server received init packet from client\n");
		break;
	case REQUEST_NEW_LOBBY:
		std::cout << "Client " << sender << " has requested a new lobby.\n";
		lobbyHandler->createNewLobby("An awesome new lobby");
		break;
	case ACTION_EVENT:
		printf("server received action event packet from client\n");
		break;
	default:
		printf("error in packet types\n");
		break;
	}
}