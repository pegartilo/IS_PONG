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
	if ((score.player1 == MAX_ROUNDS - 1) || (score.player1 == MAX_ROUNDS - 1)) {
		won = true;
	}

	return won;
}

void displayScore(tScore score)
{
	cout << setw(20) << " " << "---------------------" << endl; // Top lines of the score
	cout << setw(20) << " " << "-------" << score.player1 << "-" << score.player2 << "-------" << endl;
	cout << setw(20) << " " << "---------------------" << endl; // Bottom lines of the score
}
