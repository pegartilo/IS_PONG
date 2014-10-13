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

	court.roundWinner = -1;

	//Collision-checking
	bool ballColPlayer = false;
	bool ballColWall = false;
	int player_part_collided = -1;

	ballCollidedPlayer(court.ball, court.players, ballColPlayer, player_part_collided);
	ballCollidedWall(court.ball, ballColWall);

	//Update positions of stuff calling their functions	
	updateBall(court.ball, ballColPlayer, player_part_collided, ballColWall);
	movePlayers(court.players);

	//Place Stuff
	emptyCourt(court);
	placePlayers(court, PLAYER_1_UPLEFT_EDGE_X, court.players.player1Position, PLAYER_2_UPLEFT_EDGE_X, court.players.player2Position);
	placeBall(court, court.ball.position.x, court.ball.position.y);
	placeNet(court, NET_LEFTMOST_X);

	//IsThereAWinner
	isThereAWinner(court);
	
}

//Checks wether the ball has collided with a player, and returns the part
void ballCollidedPlayer(const tBall &ball, const tPlayers &players, bool &collided, int &part) {

	int diffBallToPlayer;
	int thirdOfPlayer = (PLAYER_HEIGHT / 3);

	if (((ball.position.x - 1) == (PLAYER_1_UPLEFT_EDGE_X + PLAYER_WIDTH)) /*Check x*/ && 
		(ball.position.y >= players.player1Position) &&
		(ball.position.y <= (players.player1Position + PLAYER_HEIGHT))) /*Check y*/ { //If true, collision with player 1

		collided = true;
		//Calculate the part collided with
		diffBallToPlayer = (ball.position.x - players.player1Position);
		if (diffBallToPlayer >= (2 * thirdOfPlayer)) {
			part = 3;
		} else if (diffBallToPlayer >= thirdOfPlayer) {
			part = 2;
		} else {
			part = 1;
		}
	}
	if  (((ball.position.x + BALL_WIDTH + 1) == (PLAYER_2_UPLEFT_EDGE_X)) /*Check x*/ && 
		(ball.position.y >= players.player2Position) &&
		(ball.position.y <= (players.player2Position + PLAYER_HEIGHT))) /*Check y*/ { //If true, collision with player 2

		collided = true;
		//Calculate the part collided with
		diffBallToPlayer = (ball.position.x - players.player2Position);
		if (diffBallToPlayer >= (2 * thirdOfPlayer)) {
			part = 3;
		} else if (diffBallToPlayer >= thirdOfPlayer) {
			part = 2;
		} else {
			part = 1;
		}
	}
}

void ballCollidedWall(const tBall &ball, bool &collided) {
	collided = false;
	if (ball.position.y == 0) {
		collided = true;
	} else if (ball.position.y == COURT_HEIGHT) {
		collided = true;
	}
}
/*
//Methods so that Ball and PLayer can kno their positions
tBall getCurrentBallPosition(const tCourt court);
tPlayers getCurrentPlayerPosition(const tCourt court);
*/

int getRoundWinner(const tCourt &court) {
	return court.roundWinner;
}

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

void isThereAWinner(tCourt &court) {
	int i = 0;
	bool roundWin = false; // no one wins

	while ((i < COURT_HEIGHT) && (!roundWin)) {
		if (court.board[i][0] == Ball) {
			court.roundWinner = 1;
			roundWin = true;
		}
		else if (court.board[i][COURT_WIDTH] == Ball) {
			court.roundWinner = 2;
			roundWin = true;
		}
		i++;
	}
}