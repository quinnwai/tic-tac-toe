/*lab3sol.cpp
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: Executes the main function, which runs a tic-tac-toe game given user input
*/

#pragma once

#include <iostream>
#include "functions.h"
#include "enums.h"
#include "game.h"

using namespace std;

int main(int argc, char* argv[])
{
    //checks for right number of arguments and if argument is TicTacToe
    //see functions for declaration
    int returnValNumArgs = getNumArgs(argc, argv);
    if (returnValNumArgs != success) {
        return returnValNumArgs;
    }

    //checks for correct game type
    int returnValGameType = getGameType(argv);
    if (returnValGameType != success) {
        return returnValGameType;
    }

   //declare object to start playing tic-tac-toe
   TicTacToeGame tttGame = TicTacToeGame();
   return tttGame.play();
}
