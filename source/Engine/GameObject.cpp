#include <Engine/Composite.h>
#include <Irrlicht/irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;

class GameObject : Composite
{
private:
	s32 mass;
	vector3df position, velocity;
	ISceneManager* smgr;
public:
	GameObject(const char* name, ISceneManager* smgr) : Composite(name)
	{
		this->smgr = smgr;
	}

	~GameObject()
	{
	}
};