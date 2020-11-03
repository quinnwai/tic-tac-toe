/*board.cpp
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: Defines the material declared in "pieces.h".
Note: More in-depth function descriptions can be found in "board.h".
*/

#pragma once
#include "board.h"
#include "enums.h"
#include "functions.h"
#include "pieces.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int setBoardDims(ifstream& ifs, unsigned int& numCols, unsigned int& numRows) {
	//get first line of file containing width (numRows) and height (numHeight) values
	string str;
	string num;
	if (getline(ifs, str)) {
		//wrap str in input string stream
		istringstream iss(str);

		//if iss holds an int, set numCols (width) value by extraction. Else return error 
		if (!(iss >> numCols)) { //stream outputs value to match type
			return invalid_var_type;
		}

		//if iss holds an int, set numRows (height) value by extraction. Else return error
		if (!(iss >> numRows)) {
			return invalid_var_type;
		}
	}
	else {
		cout << "Error " << cannot_open_file << "..." << endl;
		cout << "cannot open input file" << endl;
		return cannot_open_file;
	}

	return success;
}

int setGamePieces(ifstream& ifs, vector<game_piece>& vecPieces, unsigned int numCols, unsigned int numRows) {
	string str;
	int numPushPieces = 0;

	//iterate through all lines
	while (getline(ifs, str)) {
		//wrap str in input string stream for extraction and set variables for vector
		istringstream iss(str);
		string pieceColor, name, display;
		unsigned int idxCol, idxRow, idxPiece;
		piece_color colorIdx = piece_color::invalid_color;  

		//check that all five elements are extracted from line
		if ((iss >> pieceColor) && (iss >> name) && (iss >> display) && (iss >> idxCol) && (iss >> idxRow)) {
			//create enum from color
			lowercase(pieceColor);
			colorIdx = strToEnum(pieceColor);

			//check color is not invalid and indices within bounds
			if (colorIdx != piece_color::invalid_color && (idxCol < numCols && idxRow < numRows)) {
				//using predetermined index, update color, name, display values for the game piece
				idxPiece = (idxRow * numCols) + idxCol;
				vecPieces[idxPiece].color_ = colorIdx;
				vecPieces[idxPiece].name_ = name;
				vecPieces[idxPiece].display_ = display;

				//increment to determine if at least 1 vector was succesfully updated
				++numPushPieces;
			}
		}
	}

	if (numPushPieces > 0) {
		return success;
	}
	cout << "Error " << no_well_formed_pieces << "..." << endl;
	cout << "No pieces were successfully read in" << endl;
	cout << "Please check that the game piece lines are well-formed" << endl;
	return no_well_formed_pieces;
}

int printGamePieces(const vector<game_piece>& vecPieces, unsigned int numCols, unsigned int numRows) {
	//print a 2D array starting from the top left then moving across before moving down the array.
	for (unsigned int i = 0; i < numRows; i++) {
		for (unsigned int j = 0; j < numCols; j++) {
			cout << vecPieces[((numRows - 1 - i) * (numCols)) + j].display_;
		}
		cout << endl;
	}

	return success;
}

int getAdjacentPieces(const std::vector<game_piece>& vecPieces, unsigned int numCols, unsigned int numRows) {
	//setup straights and diagonals
	int idxPiece, idxLeft, idxRight, idxUp, idxDown, idxUpLeft, idxUpRight, idxDownLeft, idxDownRight, x, y;
	bool notLeftEdge, notRightEdge, notUpEdge, notDownEdge;


	//iterate through array to print adjacent pieces to a given game piece
	for (unsigned int i = 0; i < numRows; i++) {
		for (unsigned int j = 0; j < numCols; j++) {
			idxPiece = (i * numCols) + j;

			//check if game piece is valid
			if (vecPieces[idxPiece].name_ != "") {
				cout << i << "," << j << " ";
				cout << enumToStr(vecPieces[idxPiece].color_) << " " << vecPieces[idxPiece].name_;
				cout << ": ";

				//set values for indexing adjacent pieces
				idxLeft = idxPiece - 1;
				idxRight = idxPiece + 1;
				idxUp = idxPiece + numCols;
				idxDown = idxPiece - numCols;
				idxUpLeft = idxPiece + numCols - 1;
				idxUpRight = idxPiece + numCols + 1;
				idxDownLeft = idxPiece - numCols - 1;
				idxDownRight = idxPiece - numCols + 1;

				//set values for referenced piece's x and y (horizontal and vertical) position
				x = idxPiece % numCols;
				y = idxPiece / numCols;
				notLeftEdge = (x > 0);
				notRightEdge = (x < (numCols - 1));
				notUpEdge = (y < (numRows - 1));
				notDownEdge = (y > 0);

				if (notLeftEdge && vecPieces[idxLeft].name_ != "") { //left neighbor
					cout << (idxLeft / numCols) << "," << (idxLeft % numCols) << " ";
					cout << enumToStr(vecPieces[idxLeft].color_) << " " << vecPieces[idxLeft].display_ << ";" << " ";
				}
				if (notRightEdge && vecPieces[idxRight].name_ != "") { //right neighbor
					cout << (idxRight / numCols) << "," << (idxRight % numCols) << " ";
					cout << enumToStr(vecPieces[idxRight].color_) << " " << vecPieces[idxRight].display_ << ";" << " ";
				}
				if (notUpEdge && vecPieces[idxUp].name_ != "") { //neighbor above
					cout << (idxUp / numCols) << "," << (idxUp % numCols) << " ";
					cout << enumToStr(vecPieces[idxUp].color_) << " " << vecPieces[idxUp].display_ << ";" << " ";
				}
				if (notDownEdge && vecPieces[idxDown].name_ != "") { //neighbor below
					cout << (idxDown / numCols) << "," << (idxDown % numCols) << " ";
					cout << enumToStr(vecPieces[idxDown].color_) << " " << vecPieces[idxDown].display_ << ";" << " ";
				}
				if (notLeftEdge && notUpEdge && vecPieces[idxUpLeft].name_ != "") { //neighbor top left
					cout << (idxUpLeft / numCols) << "," << (idxUpLeft % numCols) << " ";
					cout << enumToStr(vecPieces[idxUpLeft].color_) << " " << vecPieces[idxUpLeft].display_ << ";" << " ";
				}
				if (notRightEdge && notUpEdge && vecPieces[idxUpRight].name_ != "") { //neighbor top right
					cout << (idxUpRight / numCols) << "," << (idxUpRight % numCols) << " ";
					cout << enumToStr(vecPieces[idxUpRight].color_) << " " << vecPieces[idxUpRight].display_ << ";" << " ";
				}
				if (notLeftEdge && notDownEdge && vecPieces[idxDownLeft].name_ != "") { //neighbor bottom left
					cout << (idxDownLeft / numCols) << "," << (idxDownLeft % numCols) << " ";
					cout << enumToStr(vecPieces[idxDownLeft].color_) << " " << vecPieces[idxDownLeft].display_ << ";" << " ";
				}
				if (notRightEdge && notDownEdge && vecPieces[idxDownRight].name_ != "") { //neighbor bottom right
					cout << (idxDownRight / numCols) << "," << (idxDownRight % numCols) << " ";
					cout << enumToStr(vecPieces[idxDownRight].color_) << " " << vecPieces[idxDownRight].display_ << ";" << " ";
				}
			}
		}
			cout << endl;
	}

	return success;
}
