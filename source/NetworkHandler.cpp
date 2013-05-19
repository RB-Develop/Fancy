#include "NetworkHandler.h"

using namespace fancy;
using namespace fancy::network;

NetworkHandler::NetworkHandler()
{
	_networker = new Networker();
	_networker->openUdpSocket(0);
}

NetworkHandler::~NetworkHandler()
{
	printf("Destructor of networkhandler called\n");
	delete _networker;
}

void NetworkHandler::run()
{
	sf::Packet* packet = _networker->receiveData();

	if(packet == NULL)
	{
		return;
	}

	*packet >> _receivedPacket;

	for(std::list<PlayerPacket>::iterator i=_receivedPacket.p_list.begin(); i!=_receivedPacket.p_list.end(); ++i)
	{
		std::cout << (*i).userName << std::endl;
	}
	std::cout << _receivedPacket.packet_type << std::endl;
	onReceived();

	_receivedPacket = _nullPacket;
	packet->clear();
}

void NetworkHandler::setUserName(std::string userName)
{
	_userName = userName;
}

void NetworkHandler::sendPacketType(unsigned int type)
{
	_sendPacket.packet_type = type;
	_sendPacket.userName = _userName;

	_serializedPacket << _sendPacket;

	_networker->sendPacket(&_serializedPacket);
}

void NetworkHandler::attachScene(fancy::scene::Scene* o)
{
	_listeners.push_back(o);
}

void NetworkHandler::detachScene(fancy::scene::Scene* o)
{
	_listeners.remove(o);
}

void NetworkHandler::onReceived()
{
	std::list<fancy::scene::Scene*>::iterator iter;

	for(iter = _listeners.begin(); iter != _listeners.end(); iter++)
	{
		(*iter)->notify(this);
	}
}

FancyPacket* NetworkHandler::getPacket()
{
	return &_receivedPacket;
}