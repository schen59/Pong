#include "include\object\Ball.h"
#include "include\object\MotionObject.h"
#include "include\common\Properties.h"

#include "OgreSceneManager.h"
#include "OgreSceneNode.h"
#include "OgreVector3.h"
#include "Ogre.h"

Ball::Ball(Ogre::SceneManager* sceneManager, Ogre::Vector3 dimension) : MotionObject(sceneManager, dimension, 
																				   BALL_ORIGINAL_SPEED, BALL_MOVE_RIGHT_BOTTOM) {
	mSpin = 1000;
}

void Ball::move(const Ogre::Real time) {
	Ogre::SceneNode* sceneNode = getSceneNode();
	sceneNode->translate(getDirection() * getSpeed() * time);
	sceneNode->roll(Ogre::Degree(mSpin*time));
}

void Ball::load() {
	Ogre::SceneManager* sceneManager = getSceneManager();
	Ogre::Entity* entity = sceneManager->createEntity("Sphere.mesh");
	setEntity(entity);
}

void Ball::reverseHorizontalDirection() {
	setDirection(getDirection() * HORIZONTAL_REVERSE_FACTOR);
}

void Ball::reverseVerticalDirection() {
	setDirection(getDirection() * VERTICAL_REVERSE_FACTOR);
}

void Ball::reset() {
	setPosition(BALL_ORIGINAL_POSITION);
	setSpeed(BALL_ORIGINAL_SPEED);
}