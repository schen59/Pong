#ifndef __Properties_h_
#define __Properties_h_
#include "Ogre.h"

namespace Ogre {
	class Vector3;
}

extern const Ogre::Vector3 PADDLE_ORIGINAL_DIMENSION;
extern const Ogre::Vector3 WALL_ORIGINAL_DIMENSION;

extern const Ogre::Vector3 VERTICAL_WALL_ORIGINAL_SCALE;
extern const Ogre::Vector3 HORIZONTAL_WALL_ORIGINAL_SCALE;

extern const Ogre::Vector3 LEFT_WALL_ORIGINAL_POSITION;
extern const Ogre::Vector3 RIGHT_WALL_ORIGINAL_POSITION;
extern const Ogre::Vector3 TOP_WALL_ORIGINAL_POSITION;
extern const Ogre::Vector3 BOTTOM_WALL_ORIGINAL_POSITION;

extern const Ogre::Vector3 PADDLE_ORIGINAL_SCALE;
extern const Ogre::Vector3 RIGHT_PADDLE_ORIGINAL_POSITION;
extern const Ogre::Vector3 LEFT_PADDLE_ORIGINAL_POSITION;
extern const Ogre::Vector3 PADDLE_MOVE_UP;
extern const Ogre::Vector3 PADDLE_MOVE_DOWN;
extern const Ogre::Vector3 PADDLE_ORIGINAL_SPEED;

extern const Ogre::Vector3 BALL_MOVE_RIGHT_BOTTOM;
extern const Ogre::Vector3 BALL_ORIGINAL_DIMENSION;
extern const Ogre::Vector3 BALL_ORIGINAL_SCALE;
extern const Ogre::Vector3 BALL_ORIGINAL_POSITION;
extern const Ogre::Vector3 BALL_ORIGINAL_SPEED;

extern const Ogre::Vector3 HORIZONTAL_REVERSE_FACTOR;
extern const Ogre::Vector3 VERTICAL_REVERSE_FACTOR;

extern const Ogre::Vector3 SPEED_INC_STEP;
extern const Ogre::Vector3 MAX_SPEED;

#endif