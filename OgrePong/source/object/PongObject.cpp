#include "include\object\PongObject.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreEntity.h"
#include "OgreVector3.h"

PongObject::PongObject(Ogre::SceneManager* sceneManager, Ogre::Vector3 dimension) {
	mSceneManager = sceneManager;
	mDimension = dimension;
}

void PongObject::addToScene() {
	mSceneNode = mSceneManager->getRootSceneNode()->createChildSceneNode();
	mSceneNode->attachObject(mEntity);
}

Ogre::Vector3 PongObject::getPosition() const {
	return mSceneNode->getPosition();
}

void PongObject::setPosition(Ogre::Vector3 position) {
	mSceneNode->setPosition(position);
}

void PongObject::setScale(Ogre::Vector3 scale) {
	mSceneNode->scale(scale);
}

Ogre::Vector3 PongObject::getDimension() const {
	return mDimension * mSceneNode->getScale();
}

bool PongObject::hitHorizontallyWith(const PongObject* pongObject) {
	Ogre::Vector3 position = pongObject->getPosition();
	Ogre::Vector3 dimension = pongObject->getDimension();
	Ogre::Vector3 myPosition = getPosition();
	Ogre::Vector3 myDimension = getDimension();
	return fabs(myPosition.x - position.x) <= (myDimension.x + dimension.x)/2 && 
		myPosition.y >= position.y-dimension.y/2 && myPosition.y <= position.y+dimension.y/2;
}

bool PongObject::hitVerticallyWith(const PongObject* pongObject) {
	Ogre::Vector3 position = pongObject->getPosition();
	Ogre::Vector3 dimension = pongObject->getDimension();
	Ogre::Vector3 myPosition = getPosition();
	Ogre::Vector3 myDimension = getDimension();
	return fabs(myPosition.y - position.y) <= (myDimension.y + dimension.y)/2 &&
		myPosition.x >= position.x-dimension.x/2 && myPosition.x <= position.x+dimension.x/2;
}

bool PongObject::atLeftArea() const {
	Ogre::Vector3 position = getPosition();
	return position.x < 0;
}

bool PongObject::atRightArea() const {
	Ogre::Vector3 position = getPosition();
	return position.x > 0;
}

bool PongObject::atTopArea() const {
	Ogre::Vector3 position = getPosition();
	return position.y > 0;
}

bool PongObject::atBottomArea() const {
	Ogre::Vector3 position = getPosition();
	return position.y < 0;
}
