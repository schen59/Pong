#ifndef __Ball_h_
#define __Ball_h_
#include "include\object\MotionObject.h"
#include "Ogre.h"

namespace Ogre {
	class SceneManager;
	class Vector3;
}

class MotionObject;

/**
* Class for ball object.
* @author Shaofeng Chen
* @since 2/15/14
*/
class Ball : public MotionObject {
public:
	Ball(Ogre::SceneManager* sceneManager, Ogre::Vector3 dimension);
	void load();
	void move(const Ogre::Real time);
	void reverseHorizontalDirection();
	void reverseVerticalDirection();
	void reset();

private:
	Ogre::Real mSpin;
};

#endif