#include "WorldData.h"

using namespace std;

WorldData::WorldData(PacketReceiver* observeSubject)
{
	_subject = observeSubject;
	_subject->attach(this);
}

WorldData::~WorldData()
{
	_subject->detach(this);
}

void WorldData::update(Subject* changedSubject)
{
	if(_subject != changedSubject)
		return;

	if(isOfInterest(_subject->getPacketUdp()) == false){
		return;
	}	
}

void WorldData::handleClientDisconnect(string ipAdress)
{
}