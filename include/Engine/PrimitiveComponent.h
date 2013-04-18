#ifndef FANCY_PRIM_COMP
#define FANCY_PRIM_COMP

#include <Engine/Component.h>
#include <Irrlicht/irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;

class PrimitiveComponent : public Component
{
private:
	ISceneManager* smgr;
	ISceneNode* node;

	void createCubePrimitive(f32, vector3df);
	void createSpherePrimitive(f32, vector3df);
public:
	enum PrimitiveType
	{
		PRIM_CUBE,
		PRIM_SPHERE
	};

	PrimitiveComponent(ISceneManager*, PrimitiveType, f32, vector3df = vector3df(10.0f, 0, 0));
	~PrimitiveComponent();
};

#endif