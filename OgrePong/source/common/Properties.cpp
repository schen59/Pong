#include "include\common\Properties.h"

const Ogre::Vector3 PADDLE_ORIGINAL_DIMENSION = Ogre::Vector3(2, 2, 2);
const Ogre::Vector3 WALL_ORIGINAL_DIMENSION = Ogre::Vector3(2, 2, 2);

const Ogre::Vector3 VERTICAL_WALL_ORIGINAL_SCALE = Ogre::Vector3(2.5, 70, 2.5);
const Ogre::Vector3 HORIZONTAL_WALL_ORIGINAL_SCALE = Ogre::Vector3(95, 2.5, 2.5);

const Ogre::Vector3 LEFT_WALL_ORIGINAL_POSITION = Ogre::Vector3(-95, 0, 0);
const Ogre::Vector3 RIGHT_WALL_ORIGINAL_POSITION = Ogre::Vector3(95, 0, 0);
const Ogre::Vector3 TOP_WALL_ORIGINAL_POSITION = Ogre::Vector3(0, 70, 0);
const Ogre::Vector3 BOTTOM_WALL_ORIGINAL_POSITION = Ogre::Vector3(0, -70, 0);

const Ogre::Vector3 PADDLE_ORIGINAL_SCALE = Ogre::Vector3(2.5, 15, 2.5);
const Ogre::Vector3 RIGHT_PADDLE_ORIGINAL_POSITION = Ogre::Vector3(85, 0, 0);
const Ogre::Vector3 LEFT_PADDLE_ORIGINAL_POSITION = Ogre::Vector3(-85, 0, 0);
const Ogre::Vector3 PADDLE_MOVE_UP = Ogre::Vector3(0, 1, 0);
const Ogre::Vector3 PADDLE_MOVE_DOWN = Ogre::Vector3(0, -1, 0);
const Ogre::Vector3 PADDLE_ORIGINAL_SPEED = Ogre::Vector3(0, 80, 0);
const Ogre::Vector3 PADDLE_DIRECTION_UP = Ogre::Vector3(0, 1, 0);
const Ogre::Vector3 PADDLE_DIRECTION_DOWN = Ogre::Vector3(0, -1, 0);

const Ogre::Vector3 BALL_MOVE_RIGHT_BOTTOM = Ogre::Vector3(1, -1, 0);
const Ogre::Vector3 BALL_ORIGINAL_DIMENSION = Ogre::Vector3(1, 1, 1);
const Ogre::Vector3 BALL_ORIGINAL_SCALE = Ogre::Vector3(5, 5, 5);
const Ogre::Vector3 BALL_ORIGINAL_POSITION = Ogre::Vector3(0, 0, 0);
const Ogre::Vector3 BALL_ORIGINAL_SPEED = Ogre::Vector3(80, 80, 0);

const Ogre::Vector3 HORIZONTAL_REVERSE_FACTOR = Ogre::Vector3(-1, 1, 1);
const Ogre::Vector3 VERTICAL_REVERSE_FACTOR = Ogre::Vector3(1, -1, 1);

const Ogre::Vector3 SPEED_INC_STEP = Ogre::Vector3(5, 5, 0);
const Ogre::Vector3 MAX_SPEED = Ogre::Vector3(200, 200, 0);
const Ogre::Vector3 PADDLE_SCALE_DEC_STEP = Ogre::Vector3(0, 2, 0);

const Ogre::Vector3 PADDLE_MIN_SCALE = Ogre::Vector3(2.5, 2.5, 2.5);