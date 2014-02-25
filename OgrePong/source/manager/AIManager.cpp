#include "include\manager\AIManager.h"
#include "include\core\World.h"
#include "include\common\PaddleMove.h"
#include "include\object\Ball.h"

#include "Ogre.h"

AIManager::AIManager(World *world) : mWorld(world) {
    mNextMove = MOVE_UP;
}

AIManager::~AIManager() {  
}

void AIManager::think(float time)
{
	calculateNextMove();
}

void AIManager::calculateNextMove() {
	Ball* ball = mWorld->getBall();
	Ogre::Vector3 ballDirection = ball->getDirection();
	if (ballDirection.y > 0) {
		mNextMove = MOVE_UP;
	} else {
		mNextMove = MOVE_DOWN;
	}
}

