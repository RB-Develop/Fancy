#include "WorldData.h"

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

	if(isOfInterest(_subject->getPacket()) == false){
		printf("Can't be bothered, letting it slide. [World Data] \n");
		return;
	}	

	printf("This is of interest to me! Working on it [World Data] \n");
}