#include "Meta.h"

void initializeScore(tScore &score)
{
	score.player1 = score.player2 = 0;
}

bool updateScore(tScore &score, int roundWinner) {
	bool won = false;

	if (roundWinner == 1) {
		score.player1++;
	}
	else if (roundWinner == 2) {
		score.player2++;
	}

	// Check if one player win's
	if ((score.player1 == MAX_ROUNDS) || (score.player2 == MAX_ROUNDS)) {
		won = true;
	}

	return won;
}

void displayScore(tScore score) {
	cout << endl << endl << setw(14) << "" << "Player 1: " << score.player1;
	cout << setw(32) << "" << "Player 2: " << score.player2 << endl << endl;
}
