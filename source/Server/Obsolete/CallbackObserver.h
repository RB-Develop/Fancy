#ifndef FANCY_CALLBACK_MEDIATOR
#define FANCY_CALLBACK_MEDIATOR

#include <string>
#include <iostream>

#include <SFML/Network.hpp>
#include <NetworkData.h>

#include "Observer.h"

class CallbackObserver : Observer
{
public:
	CallbackObserver();
	~CallbackObserver();

	void handleRequest(unsigned int request, std::string sender);
};

#endif