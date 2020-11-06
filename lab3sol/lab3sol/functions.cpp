/*functions.cpp
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: Defines the function that were declared in "functions.h".
Note: More in-depth function descriptions can be found in "functions.h".
*/

#pragma once

#include "enums.h"
#include "functions.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int getNumArgs(int argc, char* argv[]) { 
	//check number of arguments
	if (argc != num_args) {
		cout << "Error " << incorrect_num_args << "..." << endl;
		cout << "You used " << argc << " argument(s)" << endl;
		cout << "Usage: " << argv[program_name] << " <game_type>" << endl;
		return incorrect_num_args;
	}
	return success;
}

int getGameType(char* argv[]) {
	//generate name of gameType from first passed cmd line argument
	string gameType;
	for (auto ptr = argv[game_type]; *ptr != '\0'; ptr++) {
		gameType += *ptr;
	}

	if (gameType == "TicTacToe") {
		return success;
	}
	cout << "Error " << no_game_type << "..." << endl;
	cout << "Game type not recognized" << endl;
	cout << "Suggested usage: " << argv[program_name] << " TicTacToe" << endl;
	return no_game_type;
}

int lowercase(string& str) {
	for (size_t i = 0; str[i] != '\0'; ++i) {
		if (65 <= str[i] && str[i] <= 90) {
			str[i] = str[i] + 32;
		}
	}
	return success;
}
