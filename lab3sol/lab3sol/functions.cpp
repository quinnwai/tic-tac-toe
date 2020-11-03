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
	if (argc != num_args) {
		cout << "Error " << incorrect_num_args << "..." << endl;
		cout << "You used " << argc << " argument(s)" << endl;
		cout << "Usage: " << argv[program_name] << " <game_type>" << endl;
		return incorrect_num_args;
	}
	else if (argc[game_type] != "TicTacToe") {
		return success;
	}
	cout << "Error" << no_game_type << "..." << endl;
	cout << "Game type not recognized" << endl;
	cout << "Suggested usage: " << argv[program_name] << "TicTacToe" << endl;
	return no_game_type;
}

int readFile(ifstream& ifs, char* ptr) {
	//iterate over c-style string to create string for file name
	string fileName;
	for (int i = 0; *(ptr + i) != '\0'; i++) {
		fileName += *(ptr + i);
	}

	//read in file name into ifs
	ifs.open(fileName.c_str());
	if (!ifs.is_open()) {
		cout << "Error " << cannot_open_file << "..." << endl;
		cout << "File could not be opened" << endl;
		return cannot_open_file;
	}
	return success;
}

int strToInt(vector<string> vecStr, vector<int>& vecNum) {
	//variable declarations
	string str;
	unsigned int countDigits = 0;
	int strToNum = 0;

	//iterate through string vector and compare char by char. If all chars are digits, push to integer vector
	for (size_t s = 0; s < vecStr.size(); s++) {
		str = vecStr[s];
		for (size_t i = 0; isdigit(str[i]) && i < str.length(); i++) {
			countDigits += 1;
		}

		if (countDigits == str.length()) {
			istringstream ss(str);
			ss >> strToNum;
			vecNum.push_back(strToNum);
		}
		else
		{
			cout << "string: " << str << endl;
		}
		countDigits = 0;
	}

	//print out new integers from vector of integers
	for (size_t s = 0; s < vecNum.size(); s++) {
		cout << "int: " << vecNum[s] << endl;
	}

	return success;
}

int lowercase(string& str) {
	for (size_t i = 0; str[i] != '\0'; ++i) {
		if (65 <= str[i] && str[i] <= 90) {
			str[i] = str[i] + 32;
		}
	}
	return success;
}
