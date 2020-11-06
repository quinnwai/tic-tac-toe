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