#include "CallbackObserver.h"

using namespace std;

CallbackObserver::CallbackObserver()
{

}

CallbackObserver::~CallbackObserver()
{
}

void CallbackObserver::handleRequest(unsigned int request, string sender)
{
	switch (request) {
	case INIT_CONNECTION:
		printf("server received init packet from client\n");
		break;
	case REQUEST_NEW_LOBBY:
		std::cout << "Client " << sender << " has requested a new lobby.\n";
		break;
	case ACTION_EVENT:
		printf("server received action event packet from %s. \n", sender.c_str());
		break;
	default:
		printf("error in packet types\n");
		break;
	}
}