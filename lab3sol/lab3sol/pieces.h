/*pieces.h
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: setup for relevant game information for the game pieces
Note: I chose to leave the color variable within the game_pieces class just in case this code is needed for future labs
*/
#pragma once

#include<string>

/*struct game_piece holds relevant variables (name and display name) and two constructors
*/
struct game_piece {
	std::string name_;
	std::string display_;
	game_piece();
	game_piece(std::string name, std::string display);
};





