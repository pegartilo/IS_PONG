#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>

#include "Court.h"
#include "Meta.h"
 
typedef struct 
{
	tCourt court;
	tScore score;
} tGame;

// FUNCTIONS 
void displayCourt(const tGame &game);
void lines();
int menu();

int main() {
	int option;
	bool finish, won;
	tGame game;

	option = menu();

	switch (option) {
	case 1:

		finish = won = false;

		while ((!finish) && (!won))
		{
			// WORK IN PROGRESS

			// ver quien ha ganado
			// won = updateScore(game.score, roundWinner); // Updates the score
		}

		break;
	case 2:
		// FUTURE IMPROVEMENTS
		break;
	}
	
	while (option != 0) {
		
	} 

	return 0;
}

int menu()
{
	int option;

	cout << "1. Execute the game" << endl;
	cout << "0. Exit" << endl;
	cin >> option;

	while (option < 0 || option > 1) {
		cout << "Invalid number. Try again";
		cin >> option;
	}

	return option;
}

void displayCourt(const tGame &game) {
	lines();
	int middle;

	middle = COURT_WIDTH / 2;

	for (int i = 0; i < COURT_HEIGHT; i++) {
		for (int j = 0; i < COURT_WIDTH; i++) {
			if (j == middle)
			{
				cout << "|";
			}
			else
			{
				// FALTAAAA
				cout << game.court.board[i][j];
			}
		}
	}


	lines();
}

void lines() {
	for (int i = 0; i < COURT_WIDTH; i++)  {
		cout << "-";
	}
	cout << endl;
}
