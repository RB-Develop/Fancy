#ifndef ENTITY
#define ENTITY

#include "Composite.h"
#include <Irrlicht\irrlicht.h>
#include <string>

using namespace irr;
using namespace core;

class GameObject : public Composite
{
private: 
	float mass;

	scene::ISceneNode* node;
	vector3d<float> force, 
		position, 
		velocity, 
		accelaration, 
		orientation, 
		angularVelocity, 
		angularAccelaration, 
		anchorPoint;
	scene::ISceneManager* smgr;
public:	
	GameObject(Composite*, scene::ISceneManager *smgr = NULL);
	~GameObject();

	virtual void update();
	virtual void createNode(io::path modelPath);
};

#endif
