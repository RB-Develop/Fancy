#include <Engine/Scene.h>

class SceneManager
{
private:
	Scene* activeScene;
	irr::scene::ISceneManager* smgr;
public:
	SceneManager(irr::scene::ISceneManager*);
	~SceneManager();

	virtual void setActiveScene(Scene*);
	virtual void update();
};