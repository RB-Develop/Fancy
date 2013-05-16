#include "ChangeManager.h"

class PacketChangeManager : public ChangeManager
{
public:
	virtual void registerPair(Subject*, Observer*);
	virtual void unregisterPair(Subject*, Observer*);
	virtual void notify();
protected:
	PacketChangeManager();
};