#include "include\core\World.h"
#include "include\object\Wall.h"
#include "include\object\Ball.h"
#include "include\object\Paddle.h"
#include "include\common\PaddleMove.h"
#include "include\common\Properties.h"
#include "include\handler\InputHandler.h"
#include "include\manager\AIManager.h"
#include "include\manager\PongManager.h"
#include "include\manager\WorldManager.h"

#include "Ogre.h"
#include "OgreMath.h"
#include "OgreSceneManager.h"
#include "OgreSceneNode.h"
#include "OgreOverlayManager.h"
#include "OgreOverlay.h"
#include "OgreFontManager.h"
#include "OgreTextAreaOverlayElement.h"
#include "OgreVector3.h"

#include <ois/ois.h>

World::World(Ogre::SceneManager *sceneManager)   : mSceneManager(sceneManager) {
	createWorldState();
	createWorldManager();
	createWalls();
	createBall();
	createPaddles();
	createOverlay();
}

World::~World() {
	delete mLeftWall;
	delete mRightWall;
	delete mTopWall;
	delete mBottomWall;
	delete mLeftPaddle;
	delete mRightPaddle;
	delete mBall;
	delete mWorldManager;
}

void World::createWorldState() {
	mLeftPlayerScore = 0;
	mRightPlayerScore = 0;
	mIsSwitched = false;
	mLevel = 1;
	mRightPlayer = mRightPaddle;
	mLeftPlayer = mLeftPaddle;
}

void World::createWorldManager() {
	mWorldManager = new WorldManager(this);
}

void World::switchPlayer() {
	Paddle *tmpPlayer = mRightPlayer;
	mRightPlayer = mLeftPlayer;
	mLeftPlayer = tmpPlayer;
	mIsSwitched = !mIsSwitched;
}

void World::createPaddles() {
	createLeftPaddle();
	createRightPaddle();
}

void World::createPlayers() {
	mRightPlayer = mRightPaddle;
	mLeftPlayer = mLeftPaddle;
}

void World::createRightPaddle() {
	mRightPaddle = new Paddle(mSceneManager, PADDLE_ORIGINAL_DIMENSION);
	mRightPaddle->load();
	mRightPaddle->addToScene();
	mRightPaddle->setScale(PADDLE_ORIGINAL_SCALE);
	mRightPaddle->setPosition(RIGHT_PADDLE_ORIGINAL_POSITION);
	mRightPlayer = mRightPaddle;
}

void World::createLeftPaddle() {
	mLeftPaddle = new Paddle(mSceneManager, PADDLE_ORIGINAL_DIMENSION);
	mLeftPaddle->load();
	mLeftPaddle->addToScene();
	mLeftPaddle->setScale(PADDLE_ORIGINAL_SCALE);
	mLeftPaddle->setPosition(LEFT_PADDLE_ORIGINAL_POSITION);
	mLeftPlayer = mLeftPaddle;
}

void World::createOverlay() {
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	mOverlay = om.getByName("Score");
	mOverlay->show();
}

void World::createWalls() {
	createLeftWall();
	createRightWall();
	createTopWall();
	createBottomWall();
}

void World::createLeftWall() {
	mLeftWall = new Wall(mSceneManager, WALL_ORIGINAL_DIMENSION);
	mLeftWall->load();
	mLeftWall->addToScene();
	mLeftWall->setScale(VERTICAL_WALL_ORIGINAL_SCALE);
	mLeftWall->setPosition(LEFT_WALL_ORIGINAL_POSITION);
}

void World::createRightWall() {
	mRightWall = new Wall(mSceneManager, WALL_ORIGINAL_DIMENSION);
	mRightWall->load();
	mRightWall->addToScene();
	mRightWall->setScale(VERTICAL_WALL_ORIGINAL_SCALE);
	mRightWall->setPosition(RIGHT_WALL_ORIGINAL_POSITION);
}

void World::createTopWall() {
	mTopWall = new Wall(mSceneManager, WALL_ORIGINAL_DIMENSION);
	mTopWall->load();
	mTopWall->addToScene();
	mTopWall->setScale(HORIZONTAL_WALL_ORIGINAL_SCALE);
	mTopWall->setPosition(TOP_WALL_ORIGINAL_POSITION);
}

void World::createBottomWall() {
	mBottomWall = new Wall(mSceneManager, WALL_ORIGINAL_DIMENSION);
	mBottomWall->load();
	mBottomWall->addToScene();
	mBottomWall->setScale(HORIZONTAL_WALL_ORIGINAL_SCALE);
	mBottomWall->setPosition(BOTTOM_WALL_ORIGINAL_POSITION);
}

void World::createBall() {
	mBall = new Ball(mSceneManager, BALL_ORIGINAL_DIMENSION);
	mBall->load();
	mBall->addToScene();
	mBall->setScale(BALL_ORIGINAL_SCALE);
	mBall->setPosition(BALL_ORIGINAL_POSITION);
}

void World::think(const Ogre::Real& time) {
	mWorldManager->doWork();
	mBall->move(time);
	mLeftPlayer->move(time);
	mRightPlayer->move(time);
}

void World::getEventFrom(PongManager *pongManager) {
	mWorldManager->getEvent(pongManager);
}

bool World::isOver() {
	if (!mIsSwitched) {
		return mLeftPlayerScore == 12;
	} else {
		return mRightPlayerScore == 12;
	}
}

void World::reset() {
	createWorldState();
	mBall->reset();
	mLeftPaddle->reset();
	mRightPaddle->reset();
}

void World::updateLevel() {
	if (mRightPlayerScore == 12 || mLeftPlayerScore == 12) {
		if (!isOver()) {
			mLevel++;
		    mLeftPlayerScore = 0;
		    mRightPlayerScore = 0;
			Ogre::Vector3 newScale = mRightPaddle->getScale() - PADDLE_SCALE_DEC_STEP;
			if (newScale.y > PADDLE_MIN_SCALE.y) {
			    mRightPaddle->setScale(mRightPaddle->getScale() - PADDLE_SCALE_DEC_STEP);
			}
		}
	}
	
}
