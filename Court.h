#ifndef Court_h
#define Court_h

//------------------
//External libraries
//------------------

#include "Constants.h"
#include "Ball.h"
#include "Player.h"
#include "Windows.h" //This probably shouldn't be here, but declared in another module upwards

//------------------
//DATA TYPES
//------------------
typedef enum {
	Ball,
	Bat,
	Net,
	Empty
} tPixel;

typedef tPixel tBoard[COURT_HEIGHT][COURT_WIDTH];

typedef struct {
	tPlayers players;
	tBall ball;
	tBoard board;
	int roundWinner;
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
void ballCollidedPlayer(const tBall &ball, const tPlayers &players, bool &collided, int &part);
void ballCollidedWall(const tBall &ball, bool &collided);

int getRoundWinner(const tCourt &court);


/** INTERNAL FUNCTIONS*/

//Initializes court with starting positions of players, ball and all that
tCourt initializeCourt();

//Delete the players and the ball from the array
void deletePlayersAndBall(tCourt &court);

//Procedures to place players, ball...
void placePlayers(tCourt &court, int player1x, int player2x);
void placeBall(tCourt &court, int ball_x, int ball_y);
void placeNet(tCourt &court, int net_x);
void emptyCourt(tCourt &court);

bool isThereAWinner(tCourt &court);

#endif
