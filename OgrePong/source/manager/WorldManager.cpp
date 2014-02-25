#include "include\manager\WorldManager.h"
#include "include\core\World.h"
#include "include\manager\PongManager.h"
#include "include\object\Paddle.h"
#include "include\object\Wall.h"
#include "include\object\Ball.h"
#include "include\handler\InputHandler.h"
#include "include\manager\AIManager.h"
#include "include\common\PaddleMove.h"
#include "include\common\Properties.h"

#include "OgreOverlayManager.h"
#include "OgreTextAreaOverlayElement.h"
#include "Ogre.h"

WorldManager::WorldManager(World *world) {
	mWorld = world;
}

void WorldManager::doWork() {
	updateScore();
	updateObjects();
}

void WorldManager::getEvent(const PongManager *pongManager) {
	const InputHandler *inputHandler = pongManager->getInputHandler();
	const AIManager* aiManager = pongManager->getAIManager();
	if (inputHandler->isKeyDown(OIS::KC_LEFT)) {
		updateRightPlayer(MOVE_DOWN);
	} else if (inputHandler->isKeyDown(OIS::KC_RIGHT)) {
		updateRightPlayer(MOVE_UP);
	} else {
		updateRightPlayer(NO_MOVE);
	}
	if (inputHandler->isKeyDown(OIS::KC_S) && !inputHandler->wasKeyDown(OIS::KC_S)) {
		mWorld->switchPlayer();
	}
	updateLeftPlayer(aiManager->nextMove());
}

bool WorldManager::isLeftPlayerHitBottomWall() {
	Paddle *leftPlayer = mWorld->getLeftPlayer();
	Wall *bottomWall = mWorld->getBottomWall();
	return leftPlayer->hitVerticallyWith(bottomWall);
}

bool WorldManager::isRightPlayerHitTopWall() {
	Paddle *rightPlayer = mWorld->getRightPlayer();
	Wall *topWall = mWorld->getTopWall();
	return rightPlayer->hitVerticallyWith(topWall);
}

bool WorldManager::isRightPlayerHitBottomWall() {
	Paddle *rightPlayer = mWorld->getRightPlayer();
	Wall *bottomWall = mWorld->getBottomWall();
	return rightPlayer->hitVerticallyWith(bottomWall);
}

bool WorldManager::isBallHitByRightPaddle() {
	Ball *ball = mWorld->getBall();
	Paddle *rightPaddle = mWorld->getRightPaddle();
	return ball->hitHorizontallyWith(rightPaddle);
}

bool WorldManager::isBallCollideWithTopWall() {
	Ball *ball = mWorld->getBall();
	Wall *topWall = mWorld->getTopWall();
	return ball->hitVerticallyWith(topWall);
}

bool WorldManager::isBallCollideWithBottomWall() {
	Ball *ball = mWorld->getBall();
	Wall *bottomWall = mWorld->getBottomWall();
	return ball->hitVerticallyWith(bottomWall);
}

bool WorldManager::isBallCollideWithLeftWall() {
	Ball *ball = mWorld->getBall();
	Wall *leftWall = mWorld->getLeftWall();
	return ball->hitHorizontallyWith(leftWall);
}

bool WorldManager::isBallCollideWithRightWall() {
	Ball *ball = mWorld->getBall();
	Wall *rightWall = mWorld->getRightWall();
	return ball->hitHorizontallyWith(rightWall);
}

bool WorldManager::isLeftPlayerHitTopWall() {
	Paddle *leftPlayer = mWorld->getLeftPlayer();
	Wall *topWall = mWorld->getTopWall();
	return leftPlayer->hitVerticallyWith(topWall);
}

bool WorldManager::isBallHitByLeftPaddle() {
	Ball *ball = mWorld->getBall();
	Paddle *leftPaddle = mWorld->getLeftPaddle();
	return ball->hitHorizontallyWith(leftPaddle);
}

void WorldManager::updateScore() {
	int rightPlayerScore = mWorld->getRightPlayerScore();
	int leftPlayerScore = mWorld->getLeftPlayerScore();
	if (isBallCollideWithLeftWall()) {
		mWorld->setRightPlayerScore(++rightPlayerScore);
	}
	if (isBallCollideWithRightWall()) {
		mWorld->setLeftPlayerScore(++leftPlayerScore);
	}
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	Ogre::TextAreaOverlayElement *te = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("left");
	char score[25];
	sprintf(score, "%i", leftPlayerScore);
	te->setCaption(score);
	sprintf(score, "%i", rightPlayerScore);
	te = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("right");
	te->setCaption(score);
}

void WorldManager::updateObjects() {
	Ball *ball = mWorld->getBall();
	Paddle *leftPlayer = mWorld->getLeftPlayer();
	Paddle *rightPlayer = mWorld->getRightPlayer();
	if (isBallHitByLeftPaddle() || isBallHitByRightPaddle()) { 
		ball->reverseHorizontalDirection();
		putBallAtPaddleEdge();
		ball->setSpeed(ball->getSpeed() + SPEED_INC_STEP);
	    leftPlayer->setSpeed(leftPlayer->getSpeed() + SPEED_INC_STEP);
	    rightPlayer->setSpeed(rightPlayer->getSpeed() + SPEED_INC_STEP);
	} 
	if (isBallCollideWithTopWall() || isBallCollideWithBottomWall()) {
		ball->reverseVerticalDirection();
		putBallAtWallEdge();
	}
	if (isBallCollideWithLeftWall() || isBallCollideWithRightWall()) {
		ball->reset();
		leftPlayer->reset();
		rightPlayer->reset();
	}
}

void WorldManager::putBallAtWallEdge() {
	Ball *ball = mWorld->getBall();
	if (ball->atTopArea()) {
		putBallAtTopWallEdge();
	} else {
		putBallAtBottomWallEdge();
	}
}

void WorldManager::putBallAtPaddleEdge() {
	Ball *ball = mWorld->getBall();
	if (ball->atLeftArea()) {
		putBallAtLeftPaddleEdge();
	} else {
		putBallAtRightPaddleEdge();
	}
}

void WorldManager::updateLeftPlayer(PaddleMove direction) {
	Paddle *leftPlayer = mWorld->getLeftPlayer();
	if (direction == MOVE_DOWN && !isLeftPlayerHitBottomWall()) {
		leftPlayer->setDirection(Ogre::Vector3(0, -1, 0));
	} else if (direction == MOVE_UP && !isLeftPlayerHitTopWall()) {
		leftPlayer->setDirection(Ogre::Vector3(0, 1, 0));
	} else {
		leftPlayer->stop();
	}
}

void WorldManager::updateRightPlayer(PaddleMove direction) {
	Paddle *rightPlayer = mWorld->getRightPlayer();
	if (direction == MOVE_DOWN && !isRightPlayerHitBottomWall()) {
		rightPlayer->setDirection(Ogre::Vector3(0, -1, 0));
	} else if (direction == MOVE_UP && !isRightPlayerHitTopWall()) {
		rightPlayer->setDirection(Ogre::Vector3(0, 1, 0));
	} else {
		rightPlayer->stop();
	}
}

void WorldManager::putBallAtBottomWallEdge() {
	Wall *bottomWall = mWorld->getBottomWall();
	Ball *ball = mWorld->getBall();
	Ogre::Vector3 bottomWallPosition = bottomWall->getPosition();
	Ogre::Vector3 bottomWallDimension = bottomWall->getDimension();
	Ogre::Vector3 ballPosition = ball->getPosition();
	Ogre::Vector3 ballDimension = ball->getDimension();
	ballPosition.y = bottomWallPosition.y + (bottomWallDimension.y + ballDimension.y)/2;
	ball->setPosition(ballPosition);
}

void WorldManager::putBallAtTopWallEdge() {
	Wall *topWall = mWorld->getTopWall();
	Ball *ball = mWorld->getBall();
	Ogre::Vector3 topWallPosition = topWall->getPosition();
	Ogre::Vector3 topWallDimension = topWall->getDimension();
	Ogre::Vector3 ballPosition = ball->getPosition();
	Ogre::Vector3 ballDimension = ball->getDimension();
	ballPosition.y = topWallPosition.y - (topWallDimension.y + ballDimension.y)/2;
	ball->setPosition(ballPosition);
}

void WorldManager::putBallAtLeftPaddleEdge() {
	Paddle *leftPaddle = mWorld->getLeftPaddle();
	Ball *ball = mWorld->getBall();
	Ogre::Vector3 leftPaddlePosition = leftPaddle->getPosition();
	Ogre::Vector3 leftPaddleDimension = leftPaddle->getDimension();
	Ogre::Vector3 ballPosition = ball->getPosition();
	Ogre::Vector3 ballDimension = ball->getDimension();
	ballPosition.x = leftPaddlePosition.x + (leftPaddleDimension.x + ballDimension.x)/2;
	ball->setPosition(ballPosition);
}

void WorldManager::putBallAtRightPaddleEdge() {
	Paddle *rightPaddle = mWorld->getRightPaddle();
	Ball *ball = mWorld->getBall();
	Ogre::Vector3 rightPaddlePosition = rightPaddle->getPosition();
	Ogre::Vector3 rightPaddleDimension = rightPaddle->getDimension();
	Ogre::Vector3 ballPosition = ball->getPosition();
	Ogre::Vector3 ballDimension = ball->getDimension();
	ballPosition.x = rightPaddlePosition.x - (rightPaddleDimension.x + ballDimension.x)/2;
	ball->setPosition(ballPosition);
}
