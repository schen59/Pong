#ifndef __OgrePong_h_
#define __OgrePong_h_

// Including header files within header files is frowned upon,
// but this one is requried for Ogre Strings.
#include "OgrePrerequisites.h"
#include "OgreWindowEventUtilities.h"

namespace Ogre {
    class Root;
    class RenderWindow;
    class Camera;
    class SceneManager;
	class OverlaySystem;
}
class AIManager;
class InputHandler;
class World;
class PongCamera;
class PongManager;

/**
* Class to set up configuration, root and resources etc.
* @author Shaofeng Chen
* @since 2/15/14
*/
class OgrePong :  public Ogre::WindowEventListener
{
public:
    OgrePong();
    ~OgrePong();
    bool setup(void);
    void go(void);

private:
    void setupRoot();
    void setupResources(void);
    bool configure(void);
	void setupPongManager(void);
	void setupSceneManager();
	void setupOverlaySystem();
	void setupResourceGroup();

	PongManager *mPongManager;
	Ogre::SceneManager* mSceneManager;
    Ogre::Root *mRoot;
    Ogre::RenderWindow* mWindow;
    Ogre::String mResourcePath;
	Ogre::OverlaySystem *mOverlaySystem;
};

#endif