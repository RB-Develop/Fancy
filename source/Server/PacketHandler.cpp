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

void PacketHandler::receiveData()
{
	receiveTcpData();
	receiveUdpData();
}

void PacketHandler::receiveTcpData()
{		
	list<Packet> tcpSerData = _tcpHandler->receiveData();

	if(tcpSerData.size() <= 0) {
		return;
	}

	for(list<Packet>::iterator it = tcpSerData.begin(); it != tcpSerData.end(); it++){
		if((*it).getDataSize() > 0)
		{
			std::printf("Receiving \n");
			FancyPacket tcpData;
			(*it)>>tcpData;
			notify(tcpData);
		}
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
	std::printf("Receiving \n");
	FancyPacket udpData;
	*udpSerData>>udpData;

	notify(udpData);
	delete udpSerData;
}

void PacketHandler::notify(FancyPacket packet)
{
	Subject::notify(packet);
}