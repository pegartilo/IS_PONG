#ifndef Meta_h
#define Meta_h
	
#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>

const int MAX_ROUNDS = 3;

typedef struct {
	int player1;
	int player2;
} tScore;

void initializeScore(tScore &score);
bool updateScore(tScore &score, int winner);
void displayScore(tScore score);

#endif
