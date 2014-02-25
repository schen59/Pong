#ifndef __InputHandler_h_
#define __InputHandler_h_

#include <ois/ois.h>
#include <Ogre.h>
#include "OgreRenderWindow.h"

class World;
class PongCamera;
class InputHandler;

/**
* Class to handle the keyboard input event.
* @author Shaofeng Chen
* @since 2/15/14
*/
class InputHandler 
{
public:
	InputHandler(Ogre::RenderWindow* win);
	~InputHandler();
	void think(float time);
	bool isKeyDown(OIS::KeyCode key) const;
	bool wasKeyDown(OIS::KeyCode key) const;

protected:
	OIS::InputManager* mInputManager;
	Ogre::RenderWindow *mRenderWindow;
	OIS::Keyboard *mPreviousKeyboard;
	OIS::Keyboard *mCurrentKeyboard;
	char mOldKeys[256];
};

#endif