#ifndef COMPONENT
#define COMPONENT

class Component
{
public:
	virtual ~Component() = 0;

	const char* getName() { return _name; }

	virtual void init() {};
	virtual void update() {};
	virtual void handleMessage(unsigned int, void* data = 0) { };
protected:
	Component(const char*);
private:
	const char* _name;
};


#endif

