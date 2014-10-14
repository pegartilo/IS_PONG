#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>
#include <Windows.h>

#include "Court.h"
#include "Meta.h"

// CONSTS
const int SLEEP = 100; // stop the execution during X miliseconds 

// ENUM
typedef enum {
	black, dark_blue, dark_green, dark_cyan, dark_red,
	dark_magenta, dark_yellow, light_gray, dark_gray,
	light_blue, light_green, light_cyan, light_red,
	light_magenta, light_yellow, white
} tColor;

// STRUCTS

typedef struct {
	tCourt court;
	tScore score;
} tGame;

// FUNCTIONS 

int menu();
void wallLines();
void setColor(tColor color);
void displayCourt(const tCourt &court);

int main() {
	int option, roundWinner;
	bool finish, won;
	tGame game;

	option = menu();

	switch (option) {
	case 1:

		finish = won = false;
		initializeScore(game.score); // Initialize the score to 0
		game.court = initializeCourt(); // Set the initial Court

		do {
			system("cls");
			displayScore(game.score);
			displayCourt(game.court);

			updateCourt(game.court); // //Updates the court after calling the update functions on each component
			Sleep(SLEEP); // Waits for the input

			roundWinner = getRoundWinner(game.court);

			won = updateScore(game.score, roundWinner);

			if (won)
			{
				system("cls");
				displayScore(game.score);

				if (game.score.player1 == MAX_ROUNDS) {
					cout << "The player 1 wons the game";
				}
				else {
					cout << "The player 2 wons the game";
				}
			}
			/*
			if ((!won) && (roundWinner != -1)) { //Bugged as shit
				game.court = initializeCourt(); // Won round, reset the board
			}
			*/
		} while ((!finish) && (!won));

		break;
	case 2:
		// FUTURE IMPROVEMENTS
		break;
	}
	option = menu();

	return 0;
}

int menu() {
	int option;

	cout << endl;
	cout << "1. Execute the game" << endl;
	cout << "0. Exit" << endl;
	cin >> option;

	while (option < 0 || option > 1) {
		cout << "Invalid number. Try again";
		cin >> option;
	}

	return option;
}

void displayCourt(const tCourt &court) {

	setColor(white);
	wallLines(); // Top Walls

	for (int i = 0; i < COURT_HEIGHT; i++) {
		for (int j = 0; j < COURT_WIDTH; j++) {
			if (court.board[i][j] == Empty)
				cout << char(32);
			else if (court.board[i][j] == Ball) {
				setColor(light_green);
				cout << char(219);
			}
			else if ((court.board[i][j] == Bat) || (court.board[i][j] == Net)) {
				setColor(white);
				cout << char(219);
			}

		}
	}

	setColor(white);
	wallLines(); //Bottom Walls
}

// Print top and bottom lines on the screen

void wallLines() {
	for (int i = 0; i < COURT_WIDTH; i++)
		cout << char(196);
}

// Function for coloring the characters

void setColor(tColor color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
}
