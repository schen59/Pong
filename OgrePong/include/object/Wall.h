#ifndef __Wall_h_
#define __Wall_h_
#include "include\object\PongObject.h"

namespace Ogre {
	class SceneManager;
}

class PongObject;

/**
* Class for wall object.
* @author Shaofeng Chen
* @since 2/15/14
*/
class Wall : public PongObject {
public:
	Wall(Ogre::SceneManager* sceneManager, Ogre::Vector3 dimension);
	void load();
};

#endif