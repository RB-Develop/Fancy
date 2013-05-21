#include "Observer.h"

void Observer::setInterest(unsigned int interest)
{
	_interest = interest;
}

void Observer::addInterest(unsigned int interest)
{
	_interests.insert(interest);
}

void Observer::removeInterest(unsigned int interest)
{
	std::set<unsigned int>::iterator it;

	it = _interests.find(interest);
	if(it != _interests.end())
		_interests.erase(interest);
}

bool Observer::isOfInterest(FancyPacket* packet)
{
	std::set<unsigned int>::iterator it;

	for (it=_interests.begin(); it!=_interests.end(); ++it){
		if(packet->packet_type == *it)
			return true;
	}

	if(packet->packet_type == _interest)
		return true;
	return false;
}