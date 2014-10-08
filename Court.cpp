#include "Court.h"

//Initializes court with starting positions of players, ball and all that
tCourt initializeCourt() {
	tCourt newCourt;

	//Empty the board

	//Place Blayers
	for (int i = 0; i < PLAYER_HEIGHT; i++) {
		//Place player 1
		for (int j = 0; i < PLAYER_WIDTH; j++) {
			newCourt.board[PLAYER_1_UPLEFT_EDGE_Y + i][PLAYER_1_UPLEFT_EDGE_X + j] = Bat;
		}		
		//Place player 2
		for (int j = 0; i < PLAYER_WIDTH; j++) {
			newCourt.board[PLAYER_2_UPLEFT_EDGE_Y + i][PLAYER_2_UPLEFT_EDGE_X + j] = Bat;
		}	
	}
	//Place Ball
	for (int i = 0; i < BALL_HEIGHT; i++) {
		for(int j = 0; j < BALL_WIDTH; j++) {
			newCourt.board[BALL_START_UPLEFT_EDGE_Y + i][BALL_START_UPLEFT_EDGE_X + j] = Ball;
		}
	}
	//Place Net
	bool netOn = true;
	int netCount = 0;
	for (int i = 0; i < COURT_HEIGHT; i++) {	
		if({netCount = NET_HEIGHT) && !netOn) {
			netOn = true;
		}

		if (netOn) {
			for(int a = 0; a < NET_WIDTH; a++) {
				newCourt.board[i][NET_LEFTMOST_X + a] = Net;
			}
			if (netCount = NET_HEIGHT) {
				netOn = false;
				netCount = 0;
			}
		} 
		netCount++;
	}

	return newCourt;
}

//Updates the court with new information from the ball
void updateCourt(tCourt &court, tPlayerPosition newPlayer1Position, tPlayerPosition newPlayer2Position, tBallPosition newBallPosition);

//Methods so that Ball and PLayer can kno their positions
tBallPosition getCurrentBallPosition(const tCourt court);
tPlayerPosition getCurrentPlayerPosition(const tCourt court);