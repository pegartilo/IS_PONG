#ifndef Constants_h
#define Constants_h

//------------------
//GLOBAL CONSTANTS
//------------------
const int COURT_HEIGHT = 40;
const int COURT_WIDTH = 79;

//PLAYER measures
const int PLAYER_WIDTH = 2;
const int PLAYER_HEIGHT = 5;
	//The position of the leftmost uppermost edge 
	//in the player, to calculate starting position
const int PLAYER_1_UPLEFT_EDGE_Y = 17;
const int PLAYER_1_UPLEFT_EDGE_X = 4;
const int PLAYER_2_UPLEFT_EDGE_Y = 17;
const int PLAYER_2_UPLEFT_EDGE_X = 74;

//BALL measures
const int BALL_WIDTH = 2;
const int BALL_HEIGHT = 2;
const int BALL_START_UPLEFT_EDGE_X = 30;
const int BALL_START_UPLEFT_EDGE_Y = 15;

//NET measures
const int NET_LEFTMOST_X = 36;
const int NET_WIDTH = 2;
const int NET_PIECE_HEIGHT = 5;

#endif // !Constants_h