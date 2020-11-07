/*functions.h
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: Lists and describes more general functions required within the main program. Carried over from Lab 1
*/
#pragma once

/*Given the number of arguments, checks that there are the right amount of arguments. If not, print usage function
*/
int getNumArgs(int argc, char* argv[]);

/*Given the argument pointer array, create a string using the first argument and make sure it is "TicTacToe"
*/
int getGameType(char* argv[]);
