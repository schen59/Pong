#include "include\object\Wall.h"
#include "include\object\PongObject.h"

#include "Ogre.h"
#include "OgreSceneManager.h"

Wall::Wall(Ogre::SceneManager* sceneManager, Ogre::Vector3 dimension):PongObject(sceneManager, dimension) {}

void Wall::load() {
	Ogre::SceneManager* sceneManager = getSceneManager();
	Ogre::Entity* entity = sceneManager->createEntity("Cube.mesh");
	setEntity(entity);
}
