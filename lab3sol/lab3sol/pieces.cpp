/*pieces.cpp
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: Defines the functions and structs declared in "pieces.h".
Note: More in-depth function descriptions can be found in "pieces.h".
*/

#pragma once
#include "pieces.h"
#include "functions.h"
#include "enums.h"
#include <iostream>

using namespace std;

string enumToStr(piece_color pc) { //implemented right?
	//switch statement?

	if (pc == piece_color::red) {
		return "red";
	}
	else if (pc == piece_color::blue) {
		return "blue";
	}
	else if (pc == piece_color::black) {
		return "black";
	}
	else if (pc == piece_color::white) {
		return "white";
	}
	else if (pc == piece_color::no_color) {
		return "";
	}
	else {
		return "invalid";
	}
}

piece_color strToEnum(string str) {
	if (str == "red") {
		return piece_color::red;
	}
	else if (str == "blue") {
		return piece_color::blue;
	}
	else if (str == "black") {
		return piece_color::black;
	}
	else if (str == "white") {
		return piece_color::white;
	}
	else if (str == "" || str == " " || str == "\n" || str == "\v") {
		return piece_color::no_color;
	}
	else {
		return piece_color::invalid_color;
	}
}

game_piece::game_piece()
	:color_(piece_color::invalid_color), name_(""), display_(" ")  {};

game_piece::game_piece(piece_color color, std::string name, std::string display)
	: color_(color), name_(name), display_(display) {};