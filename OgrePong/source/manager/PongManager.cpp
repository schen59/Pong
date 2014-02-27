#include "include\manager\PongManager.h"
#include "include\manager\AIManager.h"
#include "include\handler\InputHandler.h"
#include "include\core\World.h"
#include "include\common\PaddleMove.h"

#include "OgreCamera.h"
#include "OgreColourValue.h"
#include "OgreOverlayManager.h"
#include "OgreOverlay.h"
#include "Ogre.h"
#include <ois.h>

PongManager::PongManager(Ogre::SceneManager* sceneManager, Ogre::RenderWindow *mainWindow) : mSceneManager(sceneManager), mRenderWindow(mainWindow) {
	mIsPaused = false;
	mIsOver = false;
	createGameOverOverlay();
}

// On every frame, call the appropriate managers
bool PongManager::frameStarted(const Ogre::FrameEvent &evt) {
	Ogre::Real time = evt.timeSinceLastFrame;
	if (time > 0.5) {
		time = 0.5;
	}
	mInputHandler->think(time);
	think(time);
	if (!mIsPaused && !mIsOver) {
	    mAIManager->think(time);
	    mWorld->think(time);
	}
	return mKeepGoing;
}

void PongManager::think(const Ogre::Real& time) {
	if (mInputHandler->isKeyDown(OIS::KC_ESCAPE) || mRenderWindow->isClosed()) {
		mKeepGoing = false;
	}
	if (mInputHandler->isKeyDown(OIS::KC_P) && !mInputHandler->wasKeyDown(OIS::KC_P)) {
		mIsPaused = !mIsPaused;
	}
	if (mInputHandler->isKeyDown(OIS::KC_RETURN) && !mInputHandler->wasKeyDown(OIS::KC_RETURN)) {
		startOver();
	}
	if (mWorld->isOver()) {
		mIsOver = true;
		mGameOverOverlay->show();
	}
	if (!mIsPaused && !mIsOver) {
		mWorld->getEventFrom(this);
	}
}

void PongManager::startOver() {
	mIsPaused = false;
	mIsOver = false;
	mGameOverOverlay->hide();
	mWorld->reset();
}

void PongManager::createLeftCamera() {
	mLeftCamera = mSceneManager->createCamera("PlayerLeftCam");
	mLeftCamera->setPosition(Ogre::Vector3(-200, 0, 300));
	mLeftCamera->lookAt(Ogre::Vector3(0, 0, 0));
	mLeftCamera->roll(Ogre::Degree(-90.0f));
}

void PongManager::createRightCamera() {
	mRightCamera = mSceneManager->createCamera("PlayerRightCam");
	mRightCamera->setPosition(Ogre::Vector3(200, 0, 300));
	mRightCamera->lookAt(Ogre::Vector3::ZERO);
	mRightCamera->roll(Ogre::Degree(90.0f));
}

void PongManager::createCamera() {
	createLeftCamera();
	createRightCamera();
}

void PongManager::createLeftViewPort() {
	Ogre::Viewport* vpLeft = mRenderWindow->addViewport(mLeftCamera, 0, 0, 0, 0.5, 1);
	vpLeft->setBackgroundColour(Ogre::ColourValue(0, 0, 0));
	mLeftCamera->setAspectRatio(Ogre::Real(vpLeft->getActualWidth()) / Ogre::Real(vpLeft->getActualHeight()));
}

void PongManager::createRightViewPort() {
	Ogre::Viewport* vpRight = mRenderWindow->addViewport(mRightCamera, 100, 0.5, 0, 0.5, 1);
    vpRight->setBackgroundColour(Ogre::ColourValue(1, 1, 1));
    mRightCamera->setAspectRatio(Ogre::Real(vpRight->getActualWidth()) / Ogre::Real(vpRight->getActualHeight()));
}

void PongManager::createViewports() {
    createLeftViewPort();
	createRightViewPort();
}

void PongManager::createInputHandler() {
	mInputHandler = new InputHandler(mRenderWindow);
}

void PongManager::createAIManager() {
	mAIManager = new AIManager(mWorld);
}

void PongManager::createWorld() {
	mWorld = new World(mSceneManager);
}

void PongManager::createLight() {
	mSceneManager->setAmbientLight(Ogre::ColourValue(0.75, 0.75, 0.75));
}

void PongManager::setUp() {
	createLight();
	createCamera();
	createViewports();
	createInputHandler();
	createWorld();
	createAIManager();
}

PongManager::~PongManager() {
	delete mInputHandler;
	delete mWorld;
	delete mAIManager;
}

void PongManager::createGameOverOverlay() {
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	mGameOverOverlay = om.getByName("GameOver");
}