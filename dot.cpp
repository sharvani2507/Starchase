// Dot class functions

#include <iostream>
using namespace std;

#include "dot.h"
#include "constants.h"
#include "termfuncs.h"

// Initialising the constants of Dot class
Dot::Dot()
{
    row = 0;
    col = 0;
    eaten = false;
}

// Gets a random integer value for the location
void Dot::set_random_location(char board[ROWS][COLS])
{
    do{
        row = random_int(0, ROWS-1);
        col = random_int(0, COLS-1);
    } while (board[row][col] != SPACE || (row == MidRow || col == MidCol));
}

// Place the dots on board
void Dot::place_on_board(char board[ROWS][COLS])
{
    board[row][col] = DOTS;
}

// Check for the presence of the dot
bool Dot::check(int r, int c)
{
    return (row == r) && (col == c);
}

// Sets eaten
void Dot::set_eaten(bool is_eaten)
{
    eaten = is_eaten;
}

// Return whether eaten or not
bool Dot::was_eaten()
{
    return eaten;
}

