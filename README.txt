Content (models / etc) are stored in OgrePong/Content

Configuration files are stored in OgrePong, and are copied into the 
ouput directory as a post-build step.

If you change directory structure, be sure to modify resources.cfg and resources_d.cfg
to point at the correct places.

I organize the project into several filters as follows:

Common:
    Contains the common constants used by the project.

Core:
    Contains main, OgrePong and World class.

Handler:
    Contains the class for input handler.

Manager:
    Contains the class for AIManager and PongManager.

Object:
    Contains the class definition for all objects used in Pong.


Some functions:
    Support multiple viewports. Left viewport is for AI player and right viewport is for
human player. 

    Suport game role exchange. You can hit key 'S' to exchange the role with AI player.

    Suport game state pause and resume. You can hit key 'P' to toggle the game state.

    Support adaptively change ball sppeed and paddle sppeed according to the number of 
successfully hits in a row. 

    Support level up, when the human player wins 12 scores it will level up to the next level and the paddle size
will shrink a lit bit as well.
    
    Support game over. when the AI play wins 12 score, the game will over, you can hit 'Return' to start over again.