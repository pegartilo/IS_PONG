#include "Court.h"

//Initializes court with starting positions of players, ball and all that
tCourt initializeCourt() {
	tCourt newCourt;

	//Empty the board
	emptyCourt(newCourt);

	//Place Players
	placePlayers(newCourt,PLAYER_1_UPLEFT_EDGE_X, PLAYER_1_UPLEFT_EDGE_Y, PLAYER_2_UPLEFT_EDGE_X, PLAYER_2_UPLEFT_EDGE_Y);	

	//Place Ball
	placeBall(newCourt, BALL_START_UPLEFT_EDGE_X, BALL_START_UPLEFT_EDGE_Y);
	
	//Place Net
	placeNet(newCourt, NET_LEFTMOST_X);
	
	return newCourt;
}

//Updates the court with new information from the ball
void updateCourt(tCourt &court) {

	//Collision-checking
	bool ballCollidedPlayer = false;
	bool ballCollidedWall = false;
	int player_part_collided = -1;

	ballCollidedPlayer(ballCollidedPlayer, player_part_collided);
	ballCollidedWall(ballCollidedWall);

	//Update positions of stuff calling their functions	
	updateBall(court.ball, ballCollidedPlayer, player_part_collided, ballCollidedWall);
	movePlayers(court.players);

	//Place Stuff
	emptyCourt(court);
	placePlayers(court, PLAYER_1_UPLEFT_EDGE_X, court.players.player1Position, PLAYER_2_UPLEFT_EDGE_X, court.players.player2Position);
	placeBall(court, court.ball.position.x, court.ball.position.y);
	placeNet(court, NET_LEFTMOST_X);
}

//Checks wether the ball has collided with a player, and returns the part
void ballCollidedPlayer(bool &collided, int &part) {
	collided = false;
}
void ballCollidedWall(bool &collided);

//Methods so that Ball and PLayer can kno their positions
tBall getCurrentBallPosition(const tCourt court);
tPlayers getCurrentPlayerPosition(const tCourt court);


//Procedures to place players, ball...
void placePlayers(tCourt &court, int player_1_x, int player_1_y, int player_2_x, int player_2_y) {
	for (int i = 0; i < PLAYER_HEIGHT; i++) {
		//Place player 1
		for (int j = 0; i < PLAYER_WIDTH; j++) {
			court.board[player_1_y + i][player_1_x + j] = Bat;
		}		
		//Place player 2
		for (int j = 0; i < PLAYER_WIDTH; j++) {
			court.board[player_2_y + i][player_2_x + j] = Bat;
		}	
	}
}
void placeBall(tCourt &court, int ball_x, int ball_y) {
	for (int i = 0; i < BALL_HEIGHT; i++) {
		for(int j = 0; j < BALL_WIDTH; j++) {
			court.board[ball_y + i][ball_x + j] = Ball;		
		}
	}
}
void placeNet(tCourt &court, int net_x) {
	bool netOn = true;
	int netCount = 0;
	for (int i = 0; i < COURT_HEIGHT; i++) {	
		if((netCount = NET_PIECE_HEIGHT) && !netOn) {
			netOn = true;
		}

		if (netOn) {
			for(int a = 0; a < NET_WIDTH; a++) {
				court.board[i][net_x + a] = Net;
			}
			if (netCount = NET_PIECE_HEIGHT) {
				netOn = false;
				netCount = 0;
			}
		} 
		netCount++;
	}
}
void emptyCourt(tCourt &court){
	for (int i = 0; i < COURT_HEIGHT; i++) {
		for (int j = 0; j < COURT_WIDTH; j++) {
			court.board[i][j] = Empty;
		}
	}
}
