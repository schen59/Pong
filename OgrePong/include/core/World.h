#ifndef __World_h_
#define __World_h_
#include "Ogre.h"

namespace Ogre {
    class SceneNode;
    class SceneManager;
	class Overlay;
	class Vector3;
}

class PongManager;
class InputHandler;
class Wall;
class Ball;
class Paddle;
enum PaddleMove;
class WorldManager;

/**
* Class which is responsible for creating the world for the pong game, including walls, ball, players and overlays.
* @author Shaofeng Chen
* @since 2/15/14
*/
class World
{
public:
	
    World(Ogre::SceneManager *sceneManager);
	~World();
    void think(const Ogre::Real& time);
	void switchPlayer();
	Ball* getBall() const { return mBall; }
	void getEventFrom(PongManager *pongManager);
	Paddle* getLeftPaddle() const { return mLeftPaddle; }
	Paddle* getRightPaddle() const { return mRightPaddle; }
	Wall* getLeftWall() const { return mLeftWall; }
	Wall* getRightWall() const { return mRightWall; }
	Wall* getTopWall() const { return mTopWall; }
	Wall* getBottomWall() const { return mBottomWall; }
	Paddle* getLeftPlayer() const { return mLeftPlayer; }
	Paddle* getRightPlayer() const { return mRightPlayer; }
	int getLeftPlayerScore() const { return mLeftPlayerScore; }
	void setLeftPlayerScore(int score) { mLeftPlayerScore = score; }
	int getRightPlayerScore() const { return mRightPlayerScore; }
	void setRightPlayerScore(int score) { mRightPlayerScore = score; }

private:
	void createWalls();
	void createLeftWall();
	void createRightWall();
	void createTopWall();
	void createBottomWall();
	void createBall();
	void createPlayers();
	void createPaddles();
	void createModifiers();
	void createLeftPaddle();
	void createRightPaddle();
	void createOverlay();
	
	Ogre::SceneManager *mSceneManager;
	Ogre::Overlay* mOverlay;
	Wall* mLeftWall;
	Wall* mRightWall;
	Wall* mBottomWall;
	Wall* mTopWall;
	Ball* mBall;
	Paddle* mRightPaddle;
	Paddle* mLeftPaddle;
	Paddle* mLeftPlayer;
	Paddle* mRightPlayer;
	int mLeftPlayerScore;
	int mRightPlayerScore;
	WorldManager *mWorldManager;
};

#endif