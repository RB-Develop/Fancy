#ifndef FANCY_CALLBACK_MEDIATOR
#define FANCY_CALLBACK_MEDIATOR

#include <string>
#include <iostream>

#include <SFML/Network.hpp>
#include <NetworkData.h>

#include "LobbyHandler.h"

class CallbackMediator
{
private:
	LobbyHandler* lobbyHandler;
public:
	CallbackMediator();
	~CallbackMediator();

	void handleRequest(unsigned int request, std::string sender);
};

#endif