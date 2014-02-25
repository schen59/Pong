#ifndef __AIManager_h_
#define __AIManager_h_

enum PaddleMove;
class World;
/**
 * Manager class for the AI player which is responsible for caculating the next move for AI player.
 * @author Shaofeng Chen
 * @since 2/15/14
 */
class AIManager 
{

public:
	AIManager(World *world);
	~AIManager();
	PaddleMove nextMove() const { return mNextMove; }
    void think(float time);

private:
	void calculateNextMove();

	World *mWorld;
	PaddleMove mNextMove;

};

#endif