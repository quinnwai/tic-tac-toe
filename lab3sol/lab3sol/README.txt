Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: This README documents some errors and warnings that appeared during the building process

Errors (w/ Solutions if not apparent):
-expected a type specifier (defined vector length in constructor rather than header file)
-name followed by '::' must be a class or namespace name (for specific object, replace :: with . to scope in)
-no operator "!=" matches these operands
-expression must be a modifiable lvalue (using proper parentheses as well as == instead of = for a conditional)
-exe cannot be built (had to quit out of executable in command line)
-unknown/missing type specifier (scope into std library for string in header file)

Warnings:
-ill-defined for loop (i-- instead of i++ so loop terminates)
-game.cpp signed/unsigned mismatch (changed initial declaration)
-indexing out of bound for game board array (shifted from i to i-1)

Test Cases:
-Test invalid user input
   -Out of bounds: 0,0   0,1    1,0    5,1    1,5    5,5
   -Invalid coordinates: 0.1    0 1    0.1,5  5,0.4
   -Invalid strings:     quiT   Quit   qui    q a v  
-Test valid user input
   -coordinates
   -quit
-Test input arguments
   -Incorrect argc: lab3sol.exe
   -Incorrect game type: lab3sol.exe TicTacTo
-Test terminating conditions
   -done(): horizontals, verticals, and diagonals all tested, done at all 9 pieces so not accidentally draw()
   -draw(): something like X O X 
                           X O X
                           O X O
