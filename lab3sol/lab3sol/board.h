/*pieces.h
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: declaring for relevant game information for the game board
*/

#pragma once
#include<fstream>
#include<vector>
#include"pieces.h"

//indices corresponding to the vector which stores the game board dimensions. See the
//setBoardDims function in "board.cpp" for implementation
enum dimensions { idxNumRows, idxNumCols };

/*Parses through the first line of a txt file for the width and height of the game board
*/
int setBoardDims(std::ifstream& ifs, unsigned int& numCols, unsigned int& numRows);

/*Extracts information by line which corresponds to properties of the game peices.
Updates relevant values for game piece within a vector including their color, name, and display at the extracted indices
numCols and numRows are read in as board dimensions to compare the location of the game pieces.
*/
int setGamePieces(std::ifstream& ifs, std::vector<game_piece>& vecPieces, unsigned int numCols, unsigned int numRows);

/*Prints game pieces onto the game board. A blank space or invalid piece is denoted by a space
*/
int printGamePieces(const std::vector<game_piece>& vecPieces, unsigned int numCols, unsigned int numRows);

/*Gets the adjacent game pieces for each valid game piece
*/
int getAdjacentPieces(const std::vector<game_piece>& vecPieces, unsigned int numCols, unsigned int numRows);
