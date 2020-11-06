/*game.cpp
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: Defines the material declared in "game.h". Helps to set up the tic tac toe game
*/

#pragma once

#include "game.h"
#include "pieces.h"
#include "enums.h"
#include <sstream>

using namespace std;

//constructor definition
TicTacToeGame::TicTacToeGame() {
	Xs = game_piece("Xs", "X");
	Os = game_piece("Os", "O");
	numRound = 0;
	movesX = "Player X:";
	movesO = "Player O:";
}

//insertion operator overloading for TicTacToeGame class
std::ostream& operator<<(std::ostream& out, const TicTacToeGame& game) { //passed in since cout is relaced at all locations
	for (unsigned int i = boardWidth; i > 0; i--) {
		//labelling index per row (shift by -1 to account for unsigned int)
		out << i - 1;

		//print game pieces
		for (unsigned int j = 0; j < boardWidth; j++) {
			out << game.board[i - 1][j].display_ << " "; //TODO: fix this
		}
		out << endl;
	}

	//label index per column
	out << " 0 1 2 3 4" << endl;
	return out;
}

//checks successful completion of the game, where there are three consecutive Xs or Os
bool TicTacToeGame::done() {
	//initialize indices for printed board and vecPieces
	int x = 2; //index for middle values in the tic-tac-toe array
	int y = 1; //index iteratively incremented


	while (y < 4) {
		//make sure X/O piece exists
		if (board[x][y].name_ != "") {
			//vertical three in a row is found
			if ((board[x - 1][y].name_ == board[x][y].name_) && (board[x][y].name_ == board[x + 1][y].name_)) {
				return true;
			}

			//diagonal three in a row is found (only case needed is at the middle of the array where x is y)
			if (x == y) {
				//bottom left to top right diagonal
				if ((board[x - 1][y - 1].name_ == board[x][y].name_) && (board[x][y].name_ == board[x + 1][y + 1].name_)) {
					return true;
				}

				//top left to bottom right diagonal
				if ((board[x - 1][y + 1].name_ == board[x][y].name_) && (board[x][y].name_ == board[x + 1][y - 1].name_)) {
					return true;
				}
			}
		}

		//horizontal three in a row is found (x and y are switched to represent horizontal instead of vertical matches)
		if (board[y][x].name_ != "") {
			if ((board[y][x - 1].name_ == board[y][x].name_) && (board[y][x].name_ == board[y][x + 1].name_)) {
				return true;
			}
		}
			

		//increment and set new vecIdx to index into the board of pieces
		y++;
	}
	return false;
}

bool TicTacToeGame::draw() {
	if (numRound > maxRound - 1) {
		return true;
	}
	return false;
}

//prompts user for input to add piece to tic tac toe board or quit the game
int TicTacToeGame::prompt(unsigned int& x, unsigned int& y) {
	//user game messages
	cout << "Please enter a coordinate to place your piece on the board (example: 1,1)" << endl;
	cout << "To quit the game, type 'quit'" << endl;

	//read in values
	string input;
	cin >> input;

	//if user asks for quit, return. If not, try to extract coordinates
	if (input == "quit") {
		cout << "quitting the game..." << endl;
		return quit_game;
	}

	//iterate through string to replace , with a space (respective ASCII values of 44 and 32)
	int numCommas = 0; //keept track for valid input
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input[i] == 44) { //TODO: make sure this works
			input[i] = 32;
			++numCommas;
		}
	}

	//try to extract two numbers, making sure it was in the right format of #,#
	//numCommas ensures 1,1,1 isn't read in as 1,1 for x,y
	istringstream iss(input);
	if (numCommas == 1 && iss >> x && iss >> y) {
		return success;
	}

	return invalid_user_input;
}

//alternates turns between player X and O, while making sure moves are valid
int TicTacToeGame::turn() {
	//check if user quit game
	unsigned int x;
	unsigned int y;

	//prompt initialization
	int p = prompt(x, y);

	//iterative check until user input is valid
	while (p == invalid_user_input) {
		//flush the cin/cout stream in the case of inputs with spaces
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//re-prompt
		p = prompt(x, y);
	}

	if (p == quit_game) {
		cout << "Game has been quit" << endl;
		return quit_game;
	}

	//if within board dimensions and an empty square, add piece to game board and print board
	if (x > 0 && x < 4 && y > 0 && y < 4 && board[x][y].name_ == "") {
		//insert piece into game board starting at round 1 with player X
		++numRound;
		if (numRound % 2 == 1) {
			board[x][y] = Xs;
		}
		else {
			board[x][y] = Os;
		}

		//print game board
		cout << *this << endl;

		//print moves for each person by appending to string in TicTacToeGame object
		if (numRound % 2 == 1) {
			//add ; after first coordinate
			if (numRound > 2) {
				movesX += ";";
			}
			movesX = movesX + " " + to_string(x) + "," + to_string(y);
			cout << movesX << endl;
		}
		else {
			//add ; after first coordinate
			if (numRound > 2) {
				movesO += ";";
			}
			movesO = movesO + " " + to_string(x) + "," + to_string(y);
			cout << movesO << endl;
		}
	}

	return success;
}

//loops through game asking for input until no more moves can be made or user quits out
int TicTacToeGame::play() {
	//initial printing of empty board
	cout << *this << endl;

	//go through rounds of game
	while (!(done() || draw())) {
		int returnValTurn = turn();
		if (returnValTurn == quit_game) {
			return returnValTurn;
		}
	}

	//else (ie, done is true), display who won
	cout << "After " << numRound << " rounds..." << endl;
	if (numRound % 2 == 1) {
		cout << "Player X wins!" << endl;
	}
	else {
		cout << "Player O wins!" << endl;
	}
	return success;

	//if draw is true, then no one wins
	if (draw()) {
		cout << "No moves remains" << endl;
		cout << "This game is a draw" << endl;
		return no_winning_moves;
	}
}