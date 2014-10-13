#include"Player.h"

tPlayers resetPlayers() {
	tPlayers players;
	
	players.player1Position = COURT_HEIGHT / 2;
	players.player2Position = COURT_HEIGHT / 2;
	players.service = false;

	return players;
}

tInput keyBoardInput() {
	tInput input;

	//W key;
	input.keyCode[0] = 87;
	//S key;
	input.keyCode[1] = 83;
	//Up Arrow;
	input.keyCode[2] = VK_UP;
	//Down Arrow;
	input.keyCode[3] = VK_DOWN;
	//Space key;
	input.keyCode[4] = 32;

	for (int i = 0; i < MAXNUMBEROFKEYS; ++i) {
		if (GetKeyState(input.keyCode[i]) == -128 || GetKeyState(input.keyCode[i]) == -127)
			input.keysBeingPressed[i] = true;
		else
			input.keysBeingPressed[i] = false;
	}

	return input;
}

void transformInput(tMovement &player1Move, tMovement &player2Move, bool &service) {
	tInput input = keyBoardInput();

	if (input.keysBeingPressed[0])
		player1Move = up;
	else if (input.keysBeingPressed[1])
		player1Move = down;
	else
		player1Move = standstill;

	if (input.keysBeingPressed[2])
		player2Move = up;
	else if (input.keysBeingPressed[3])
		player2Move = down;
	else
		player2Move = standstill;

	if (input.keysBeingPressed[4])
		service = true;
	else
		service = false;
}

tPlayers movePlayers(tPlayers players) {
	tInput input;
	tMovement player1Move, player2Move;

	transformInput(player1Move, player2Move, players.service);
	if (player1Move == up && players.player1Position > 0 + (PLAYER_HEIGHT / 2)) {
		players.player1Position -= 1;
	}
	else if (player1Move == down && players.player1Position < COURT_HEIGHT - (PLAYER_HEIGHT / 2)) {
		players.player1Position += 1;
	}
	if (player2Move == up && players.player2Position > 0 + (PLAYER_HEIGHT / 2)) {
		players.player2Position -= 1;
	}
	else if (player2Move == down && players.player2Position > COURT_HEIGHT - (PLAYER_HEIGHT / 2)) {
		players.player2Position += 1;
	}

	return players;
}
