#include <map>
#include "Observer.h"
#include "Subject.h"

class ChangeManager
{
public:
	virtual ~ChangeManager();

	virtual void registerPair(Subject*, Observer*) = 0;
	virtual void unregisterPair(Subject*, Observer*) = 0;
	virtual void notify() = 0;
protected:
	ChangeManager();
private:
	std::map<Subject*, Observer*> _mapping;
};