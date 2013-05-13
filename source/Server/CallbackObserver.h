#ifndef FANCY_CALLBACK_MEDIATOR
#define FANCY_CALLBACK_MEDIATOR

#include <string>
#include <iostream>

#include <SFML/Network.hpp>
#include <NetworkData.h>

#include "LobbyHandler.h"

class CallbackObserver
{
private:
	LobbyHandler* lobbyHandler;
public:
	CallbackObserver();
	~CallbackObserver();

	void handleRequest(unsigned int request, std::string sender);
};

#endif