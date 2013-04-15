#include <Engine\Entity.h>

Entity::Entity(Composite* parent, scene::ISceneManager *smgr) : Composite(parent)
{
	this->smgr = smgr;
	mass = 1;
	node = NULL;
}

void Entity::update()
{
	Composite::update();

	angularVelocity += angularAccelaration;
	orientation += angularVelocity;
	accelaration = (1 / mass) * force;
	velocity += accelaration;
	position += velocity;

	if (node != NULL)
	{
		node->setPosition(position);
		node->setRotation(orientation);
	}
}

void Entity::draw()
{
	Composite::draw();

	if (node == NULL) 
		return;

	if (!visible)
	{
		node->setVisible(false);
		return;
	}

	node->setVisible(true);
	node->render();
}

void Entity::createNode(io::path modelPath)
{
	// Get the mesh
	node = smgr->addMeshSceneNode(smgr->getMesh(modelPath));
}

Entity::~Entity()
{
	Composite::~Composite();
	
	if (node != NULL)
		node->drop();

	smgr = NULL;
}