#include "PacketHandler.h"

using namespace std;
using namespace sf;

PacketHandler::PacketHandler(UdpHandler* udp, TcpHandler* tcp)
{
	_udpHandler = udp;
	_tcpHandler = tcp;
}

PacketHandler::~PacketHandler()
{
	_udpHandler = NULL;
	_tcpHandler = NULL;
}

void PacketHandler::sendData(FancyPacket packet, string ipAddress, unsigned short port)
{
	Packet sendPacket;
	sendPacket<<packet;

	_udpHandler->sendData(&sendPacket, &IpAddress(ipAddress), port);
}

void PacketHandler::sendData(FancyPacket packet, TcpSocket* socket)
{
	Packet sendPacket;
	sendPacket<<packet;

	_tcpHandler->sendData(&sendPacket, socket);
}

void PacketHandler::receiveData()
{
	receiveTcpData();
	receiveUdpData();
	distributeTcpData();
}

void PacketHandler::receiveTcpData()
{		
	tcpSerData = _tcpHandler->receiveData();

	if(tcpSerData.size() <= 0) {
		return;
	}

	for(list<pair<Packet, TcpSocket*>>::iterator it = tcpSerData.begin(); it != tcpSerData.end(); it++){
		FancyPacket tcpData;
		(*it).first >> tcpData;

		tcpData.ipAdress = (*it).second->getRemoteAddress().toString();
		tcpData.tcpSocket = (*it).second;

		_tcpUnserData.push_back(tcpData);
	}

	tcpSerData.clear();
}

void PacketHandler::receiveUdpData()
{
	Packet* udpSerData = _udpHandler->receiveData();

	if(udpSerData->getDataSize() <= 0) {
		delete udpSerData;
		return;
	}

	FancyPacket udpData;
	*udpSerData>>udpData;

	notify(udpData);
	delete udpSerData;
}

void PacketHandler::distributeTcpData()
{
	for(list<FancyPacket>::iterator iter = _tcpUnserData.begin(); iter != _tcpUnserData.end(); iter++)
	{
		notify(*iter);
	}
	_tcpUnserData.clear();
}

void PacketHandler::notify(FancyPacket packet)
{
	Subject::notify(packet);
}