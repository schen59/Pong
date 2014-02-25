#ifndef __PongManager_h_
#define __PongManager_h_

#include "Ogre.h"
#include "OgreFrameListener.h"

namespace Ogre
{
	class RenderWindow;
	class Camera;
	class SceneManager;
}

class InputHandler;
class AIManager;
class World;
class PongCamera;

/**
* Pong manager class which is responsible for controlling the game logic like scene creating, input handling,
* and frame listening.
* @author Shaofeng Chen
* @since 2/15/14
*/
class PongManager : public Ogre::FrameListener
{
public:
	PongManager(Ogre::SceneManager* sceneManager, Ogre::RenderWindow *mainWindow);
	~PongManager();
	bool frameStarted(const Ogre::FrameEvent &evt);
	const InputHandler* getInputHandler() const { return mInputHandler; }
	const AIManager* getAIManager() const { return mAIManager; }
	void setUp();

private:
	void createCamera();
	void createInputHandler();
	void createAIManager();
	void createWorld();
	void createViewports();
	void createLight();
	void createLeftCamera();
	void createRightCamera();
	void createLeftViewPort();
	void createRightViewPort();
	void think(const Ogre::Real& time);

	Ogre::SceneManager* mSceneManager;
	InputHandler *mInputHandler;
	AIManager *mAIManager;
	World *mWorld;
    Ogre::Camera *mLeftCamera;
	Ogre::Camera *mRightCamera;
	Ogre::RenderWindow *mRenderWindow;
	bool mKeepGoing;
	bool mIsPaused;
};

#endif