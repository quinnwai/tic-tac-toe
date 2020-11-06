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

game_piece::game_piece()
	: name_(""), display_(" ")  {};

game_piece::game_piece(string name, string display)
	: name_(name), display_(display) {};