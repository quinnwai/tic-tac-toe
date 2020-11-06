/*game.h
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: declaring for relevant setup for the tic tac toe game
*/

#pragma once

#include "board.h"
#include "pieces.h"
#include <vector>
#include <iostream>

//set relevant enums for tic tac toe-specific information
enum ticTacToeNums { boardWidth = 5, maxRound = 9 };

//create class for tic-tac-toe game
class TicTacToeGame {
private:
	game_piece board[boardWidth][boardWidth];
	game_piece Xs;
	game_piece Os;
	unsigned int numRound;
	std::string movesX;
	std::string movesO;
public:
	TicTacToeGame();     //default constructor
	friend std::ostream& operator<<(std::ostream& out, const TicTacToeGame& game);  //friend to access/overload insertion operator
	bool done();   //determines if a three in a row has been made
	bool draw();  //checks for three in a row or no remaining moves left
	int prompt(unsigned int& x, unsigned int& y); //asks for valid user input to continue the game
	int turn();   //keeps track of whose turn it is and checks for a valid input coordinate, quits game, or asks for new input
	int play();   //prints gameboard, continues to call turn() and done() and draw() to execute game until completion/termination
};

//overload insertion operator so that the game can print out the game board when the TicTacToeGame object is called
std::ostream& operator<<(std::ostream& out, const TicTacToeGame& game);