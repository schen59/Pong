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