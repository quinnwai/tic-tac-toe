/*functions.h
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: Lists and describes more general functions required within the main program. Carried over from Lab 1
*/

#pragma once
#include<vector>
#include<string>

int getNumArgs(int argc, char* argv[]);

/*Using the char pointer parameter (str), iterates through a char array by address
to get the file name. Extracts strings from the file and places them into the
vector of strings parameter (vec)
*/
int readFile(std::ifstream& ifs, char* ptr);

/*Given a vector of strings (vecStr), pushes the strings that can be converted into integers
to a vector of integers. Prints strings and integers separately:=
*/
int strToInt(std::vector<std::string> vecStr, std::vector<int>& vecNum);

/*Makes all characters in a string lowercase
*/
int lowercase(std::string& str);
