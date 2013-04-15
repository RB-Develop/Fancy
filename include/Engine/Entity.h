#include "Composite.h"

#include <Irrlicht\irrlicht.h>
#include <Irrlicht\vector3d.h>
#include <Irrlicht\irrMath.h>
#include <string>

#ifndef ENTITY
#define ENTITY

using namespace irr;
using namespace core;

class Entity : public Composite
{
	scene::ISceneManager* smgr;
public:
	float mass;
	bool visible;

	scene::ISceneNode* node;
	vector3d<float> force, position, velocity, accelaration, orientation, angularVelocity, angularAccelaration, anchorPoint;
	
	Entity(Composite* parent, scene::ISceneManager *smgr);
	~Entity();

	// Methods
	virtual void update();
	virtual void draw();
	virtual void createNode(io::path modelPath);
};

#endif
