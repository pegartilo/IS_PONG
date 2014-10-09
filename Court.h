#ifndef court
#define court

//------------------
//External libraries
//------------------

#include "ball.h"
#include "Player.h"

//------------------
//GLOBAL CONSTANTS
//------------------

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

//COURT measures
const int COURT_HEIGHT = 40;
const int COURT_WIDTH = 80;

//NET measures
const int NET_LEFTMOST_X = 36;
const int NET_WIDTH = 2;
const int NET_PIECE_HEIGHT = 5;


//------------------
//DATA TYPES
//------------------
typedef enum {
	Ball,
	Bat,
	Net,
	Empty
}tPixel;

typedef tPixel tBoard [COURT_WIDTH][COURT_HEIGHT];

typedef struct {
	tBoard board;
	tPlayers players;	
	tBall ball
} tCourt;

//------------------
//FUNCTION PROTOTYPES
//------------------

/** FOR INTERFACE */
//Updates the court after calling the update functions on each component
void updateCourt(tCourt &court);
/*
//Methods so that Ball and PLayer can kno their positions
tBallPosition getCurrentBallPosition(const tCourt court);
tPlayerPosition getCurrentPlayerPosition(const tCourt court);
*/
//Checks wether the ball has collided with a player, and returns the part
void ballCollided(const tBall &ball, const tPlayers players, bool &collided, int &part);
void ballCollidedWall(const tBall ball, bool &collided);


/** INTERNAL FUNCTIONS*/

//Initializes court with starting positions of players, ball and all that
tCourt initializeCourt();



//Delete the players and the ball from the array
void deletePlayersAndBall(tCourt &court);

//Procedures to place players, ball...
void placePlayers(tCourt &court, int player_1_x, int player_1_y, int player_2_x, int player_2_y);
void placeBall(tCourt &court, int ball_x, int ball_y);
void placeNet(tCourt &court, int net_x);
void emptyCourt(tCourt &court);

#endif