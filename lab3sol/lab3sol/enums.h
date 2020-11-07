/*enums.h
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: declare enumerations used within source files
*/

#pragma once

#include<vector>
#include<string>

//common indices to reference for command line arguments
enum program { program_name, game_type, num_args };

//different possible error types that may occur
enum errors { success, incorrect_num_args, no_game_type, quit_game, invalid_user_input, no_winning_moves };