#include "NetworkHandler.h"

using namespace fancy;
using namespace fancy::network;

NetworkHandler::NetworkHandler() : _nullPacket()
{
	_networker = new Networker();
	_networker->openUdpSocket(0);
	_networker->openTcpSocket(53000);

	_tcpPacket = sf::Packet();
}

NetworkHandler::~NetworkHandler()
{
	delete _networker;
}

void NetworkHandler::run()
{
	_networker->receiveDataUdp();
	_tcpPacket = _networker->receiveDataTcp();

	if(_tcpPacket.getDataSize() <= 4)
	{
		_tcpPacket.clear();
		return;
	}

	_tcpPacket >> _receivedPacket;

	for(std::list<PlayerPacket>::iterator i = _receivedPacket.p_list.begin(); i != _receivedPacket.p_list.end(); ++i)
	{
		std::cout << (*i).userName << " is a user.\n";
	}
	onReceived();

	_receivedPacket = _nullPacket;
	_tcpPacket.clear();
}

void NetworkHandler::setUserName(std::string userName)
{
	_userName = userName;
}

void NetworkHandler::sendPacketType(unsigned int type, unsigned int protocol)
{
	_sendPacket.packet_type = type;
	_sendPacket.userName = _userName;

	_serializedPacket << _sendPacket;

	_networker->sendPacket(&_serializedPacket, protocol);

	_sendPacket = _nullPacket;
	_serializedPacket.clear();
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