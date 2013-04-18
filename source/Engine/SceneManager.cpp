#include <Engine/SceneManager.h>

SceneManager::SceneManager(ISceneManager* smgr)
{
	activeScene = NULL;
	this->smgr = smgr;
}

SceneManager::~SceneManager()
{
	activeScene = NULL;
}

void SceneManager::setActiveScene(Scene* scene)
{
	if(activeScene != NULL)
		delete activeScene;
	activeScene = scene;
}

void SceneManager::update()
{
	activeScene->update();
}