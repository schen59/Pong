#include "include\manager\AIManager.h"
#include "include\core\World.h"
#include "include\common\PaddleMove.h"
#include "include\object\Ball.h"
#include "include\object\Paddle.h"
#include "include\object\Wall.h"
#include "include\common\Properties.h"

#include "Ogre.h"

AIManager::AIManager(World *world) : mWorld(world) {
    mNextMove = MOVE_UP;
}

AIManager::~AIManager() {  
}

void AIManager::think(float time)
{
	int i = rand();
	if (i % 10 < 9) {
	    calculateNextMoveSimple();
	} else {
		calculateNextMoveGreedy();
	}
}

void AIManager::calculateNextMoveSimple() {
	Paddle* leftPlayer = mWorld->getLeftPlayer();
	Wall* bottomWall = mWorld->getBottomWall();
	Wall* topWall = mWorld->getTopWall();
	if (leftPlayer->hitVerticallyWith(bottomWall)) {
		leftPlayer->setDirection(PADDLE_DIRECTION_UP);
	} 
	if (leftPlayer->hitVerticallyWith(topWall)) {
		leftPlayer->setDirection(PADDLE_DIRECTION_DOWN);
	}
	if (leftPlayer->getDirection() == PADDLE_DIRECTION_DOWN) {
		mNextMove = MOVE_DOWN;
	} else {
		mNextMove = MOVE_UP;
	}
}

void AIManager::calculateNextMoveGreedy() {
	Ball* ball = mWorld->getBall();
	Ogre::Vector3 ballDirection = ball->getDirection();
	if (ballDirection.y > 0) {
		mNextMove = MOVE_UP;
	} else {
		mNextMove = MOVE_DOWN;
	}
}


