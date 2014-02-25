#ifndef __MotionObject_h_
#define __MotionObject_h_

#include "include\object\PongObject.h"
#include "Ogre.h"

namespace Ogre {
	class SceneManager;
	class Vector3;
}

class PongObject;

class MotionObject : public PongObject {

public:
	MotionObject(Ogre::SceneManager *sceneManager, Ogre::Vector3 dimension, Ogre::Vector3 speed, Ogre::Vector3 direction);
	bool hitHorizontallyWith(const PongObject* pongObject);
	bool hitVerticallyWith(const PongObject* pongObject);
	bool atLeftArea() const;
	bool atRightArea() const;
	bool atTopArea() const;
	bool atBottomArea() const;
	void virtual move(const Ogre::Real time);
	Ogre::Vector3 getSpeed() { return mSpeed; }
	void setSpeed(Ogre::Vector3 speed);
	void setDirection(const Ogre::Vector3& direction) { mDirection = direction; }
	Ogre::Vector3 getDirection() const { return mDirection; }
	void virtual reset() = 0;
	void virtual load() = 0;
	void stop();

private:
	Ogre::Vector3 mDirection;
	Ogre::Vector3 mSpeed;
};

#endif