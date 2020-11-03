/*pieces.h
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: setup for relevant game information for the game pieces
*/

#pragma once
#include<string>

//possible colors for game pieces
enum class piece_color { red, blue, black, white, no_color, invalid_color };

/*takes an integer color enumeration and returns a lowercase string of its associated color
*/
std::string enumToStr(piece_color pc);

/*takes a string, makes all characters lowercase, and returns its associated color enumeration
*/
piece_color strToEnum(std::string str);

/*struct game_piece holds relevant variables (color, name, and display name)
*/
struct game_piece {
	piece_color color_;
	std::string name_;
	std::string display_;
	game_piece();
	game_piece(piece_color color, std::string name, std::string display);
};



