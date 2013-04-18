#include <Irrlicht/irrlicht.h>
#include <Engine/Scene.h>

using namespace irr;
using namespace scene;

class SceneManager
{
private:
	Scene* activeScene;
	ISceneManager* smgr;
public:
	SceneManager(ISceneManager*);
	~SceneManager();

	virtual void setActiveScene(Scene*);
	virtual void update();
};