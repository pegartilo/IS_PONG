#ifndef court
#define court

//------------------
//External libraries
//------------------

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
typedef enum tPixel{
	ball,
	bat,
	net,
	empty,
}

typedef tPixel tBoard[COURT_WIDTH, COURT_HEIGHT];

typedef struct {
	tBoard board;
	tPlayer player1;
	tPlayer player2;
	tBall
} tCourt;

//------------------
//FUNCTION PROTOTYPES
//------------------

//Initializes court with starting positions of players, ball and all that
tCourt initializeCourt();

//Updates the court with new information from the ball
updateCourt(tCourt &court, tPlayerPosition newPlayer1Position, tPlayerPosition newPlayer2Position, tBallPosition newBallPosition);

//Methods so that Ball and PLayer can kno their positions
tBallPosition getCurrentBallPosition(const tCourt court);
tPlayerPosition getCurrentPlayerPosition(const tCourt court);


#endif