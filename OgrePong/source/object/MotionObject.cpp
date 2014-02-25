#include "include\object\MotionObject.h"
#include "include\object\PongObject.h"
#include "include\common\Properties.h"

#include "Ogre.h"

MotionObject::MotionObject(Ogre::SceneManager *sceneManager, Ogre::Vector3 dimension, 
						   Ogre::Vector3 speed, Ogre::Vector3 direction) : PongObject(sceneManager, dimension) {
	mSpeed = speed;
	mDirection = direction;
}

bool MotionObject::hitHorizontallyWith(const PongObject* pongObject) {
	Ogre::Vector3 position = pongObject->getPosition();
	Ogre::Vector3 dimension = pongObject->getDimension();
	Ogre::Vector3 myPosition = getPosition();
	Ogre::Vector3 myDimension = getDimension();
	return fabs(myPosition.x - position.x) <= (myDimension.x + dimension.x)/2 && 
		myPosition.y >= position.y-dimension.y/2 && myPosition.y <= position.y+dimension.y/2;
}

bool MotionObject::hitVerticallyWith(const PongObject* pongObject) {
	Ogre::Vector3 position = pongObject->getPosition();
	Ogre::Vector3 dimension = pongObject->getDimension();
	Ogre::Vector3 myPosition = getPosition();
	Ogre::Vector3 myDimension = getDimension();
	return fabs(myPosition.y - position.y) <= (myDimension.y + dimension.y)/2 &&
		myPosition.x >= position.x-dimension.x/2 && myPosition.x <= position.x+dimension.x/2;
}

bool MotionObject::atLeftArea() const {
	Ogre::Vector3 position = getPosition();
	return position.x < 0;
}

bool MotionObject::atRightArea() const {
	Ogre::Vector3 position = getPosition();
	return position.x > 0;
}

bool MotionObject::atTopArea() const {
	Ogre::Vector3 position = getPosition();
	return position.y > 0;
}

bool MotionObject::atBottomArea() const {
	Ogre::Vector3 position = getPosition();
	return position.y < 0;
}

void MotionObject::move(const Ogre::Real time) {
	Ogre::SceneNode* sceneNode = getSceneNode();
	sceneNode->translate(mDirection * mSpeed * time);
}

void MotionObject::stop() {
	mDirection = Ogre::Vector3::ZERO;
}

void MotionObject::setSpeed(Ogre::Vector3 speed) {
	if (speed.x < MAX_SPEED.x && speed.y < MAX_SPEED.y) {
		mSpeed = speed;
	}
}