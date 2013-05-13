#include <map>
#include "Observer.h"
#include "Subject.h"

class ChangeManager
{
public:
	virtual ~ChangeManager();

	virtual void registerPair(Subject*, Observer*);
	virtual void unregisterPair(Subject*, Observer*);
	virtual void notify();
protected:
	ChangeManager();
private:
	std::map<Subject*, Observer*> _mapping;
};