#include "NetworkHandler.h"

using namespace fancy;
using namespace fancy::network;

NetworkHandler::NetworkHandler()
{
}

NetworkHandler::~NetworkHandler()
{
}

void NetworkHandler::run()
{
	char* data = Networker::instance()->receiveData();

	if (data == NULL) {
		return;
	}

	printf("Got a response! \n");

	_receivedPacket.deserialize(data);
}

FancyPacket* NetworkHandler::getPacket()
{
	return &_receivedPacket;
}