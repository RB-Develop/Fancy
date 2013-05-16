#include <Engine/Networker.h>

using namespace std;
using namespace sf;
using namespace fancy::network;

Networker::Networker()
{
	_hostPort = 54000;
	_hostAdress = "localhost";
	_data = "";
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

void Networker::setHostIp(string hostAdress)
{
	_hostAdress = hostAdress;
}

bool Networker::openUdpSocket(unsigned short port)
{
	if (_socket.bind(port) != Socket::Done)
	{
		return false;
	}	
	_socket.setBlocking(false);
	printf("UDP socket set up on port %i.\n", port);
	return true;
}

bool Networker::sendPacket(const char* packet_data, const unsigned int packet_size)
{
	if (_socket.send(packet_data, packet_size, _hostAdress, _hostPort) != Socket::Done)
	{
		printf("Can't send");
		return false;
	}
	return true;
}

char* Networker::receiveData()
{
	_socket.receive(_data, 1000, _receivedSize, _hostAdress, _hostPort);
	return _data;
}