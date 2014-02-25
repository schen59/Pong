#ifndef __Paddle_h_
#define __Paddle_h_
#include "include\object\MotionObject.h"

namespace Ogre {
	class SceneManager;
	class Vector3;
}
class MotionObject;

/**
* Class for paddle object.
* @author Shaofeng Chen
* @since 2/15/14
*/
class Paddle : public MotionObject {
public:
	Paddle(Ogre::SceneManager* sceneManager, Ogre::Vector3 dimension);
	void load();
	void reset();
};

#endif