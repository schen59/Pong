#ifndef __WorldManager_h_
#define __WorldManager_h_
#include "include/common/PaddleMove.h"
#include "Ogre.h"

class World;
class PongManager;
enum PaddleMove;

class WorldManager {
public:
	WorldManager(World *world);
	void doWork();
	void getEvent(const PongManager *pongManager);

private:
	void updateLeftPlayer(PaddleMove direction); 
	void updateRightPlayer(PaddleMove direction);
	bool isBallCollideWithLeftWall();
	bool isBallCollideWithRightWall();
	bool isBallCollideWithTopWall();
	bool isBallCollideWithBottomWall();
	bool isLeftPlayerHitTopWall();
	bool isLeftPlayerHitBottomWall();
	bool isRightPlayerHitTopWall();
	bool isRightPlayerHitBottomWall();
	bool isBallHitByRightPaddle();
	bool isBallHitByLeftPaddle();
	void updateObjects();
	void putBallAtWallEdge();
	void putBallAtPaddleEdge();
	void putBallAtTopWallEdge();
	void putBallAtBottomWallEdge();
	void putBallAtLeftPaddleEdge();
	void putBallAtRightPaddleEdge();
	void updateScore();

	World *mWorld;
};

#endif