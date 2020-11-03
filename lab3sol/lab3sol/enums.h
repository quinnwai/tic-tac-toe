/*enums.h
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: declare enumerations used within source files
*/

#pragma once

#include<vector>
#include<string>

//common indices to reference for command line arguments
enum program {program_name, game_type, num_args};

//different possible error types that may occur
enum errors { success, cannot_open_file, incorrect_num_args, invalid_var_type, no_well_formed_pieces, vec_size_mismatch, no_game_type};