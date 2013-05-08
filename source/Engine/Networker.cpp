#include <Engine/Networker.h>

using namespace sf;
using namespace fancy::network;

Networker::Networker()
{
	_packetHandler = new PacketHandler("localhost");
}

Networker* Networker::_instance = 0;

Networker* Networker::instance()
{
	if(_instance == 0)
	{
		_instance = new Networker();
	}
	return _instance;
}

bool Networker::openUdpSocket(unsigned short port)
{
	if (_socket.bind(port) != Socket::Done)
	{
		return false;
	}	
	return true;
}

bool Networker::registerUsername(char* username)
{
	_username = username;
	return true;
}