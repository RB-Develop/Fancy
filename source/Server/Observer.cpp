#include "Observer.h"

void Observer::setInterest(unsigned int interest)
{
	_interest = interest;
}

bool Observer::isOfInterest(FancyPacket* packet)
{
	if(packet->packet_type == _interest)
		return true;
	return false;
}