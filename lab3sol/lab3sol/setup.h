/*setup.h
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: declaring for relevant setup for the tic tac toe game
*/

#pragma once

enum board {boardLen = 5};

//create class for tic-tac-toe game
class TicTacToeGame {
private:
	char board[boardLen][boardLen];

public:
	TicTacToeGame();
};