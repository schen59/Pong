#include "include\object\Paddle.h"
#include "include\object\MotionObject.h"
#include "include\common\Properties.h"

#include "OgreSceneManager.h"

Paddle::Paddle(Ogre::SceneManager* sceneManager, Ogre::Vector3 dimension) : MotionObject(sceneManager, dimension, 
																						 PADDLE_ORIGINAL_SPEED, Ogre::Vector3(0, 1, 0)) {
}

void Paddle::load() {
	Ogre::SceneManager* sceneManager = getSceneManager();
	Ogre::Entity* entity = sceneManager->createEntity("Cube.mesh");
	setEntity(entity);
}

void Paddle::reset() {
	Ogre::Vector3 position = getPosition();
	position.y = 0;
	setPosition(position);
	setSpeed(PADDLE_ORIGINAL_SPEED);
}
