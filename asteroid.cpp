// Ghost class functions

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "asteroids.h"
#include "constants.h"
#include "termfuncs.h"

// Initialising the constants of Asteroids class
Asteroid::Asteroid()
{
        row = 0;
        col = 0;
        board_char = SPACE;
}

// Set the location
void Asteroid::set_location(int r, int c)
{
        row = r;
        col = c;
}

// Set random location
void Asteroid::set_random_location()
{
        do {
                row = random_int(0, ROWS-1);
                col = random_int(0, COLS-1);
           } while (row == MidRow || col == MidCol);
}

// Chase the star algorithm
bool Asteroid::move(char board[ROWS][COLS], int target_r, int target_c)
{
        int new_row = row;
        int new_col = col; 
        board[row][col] = board_char;
        if (abs(row-target_r) > abs(col-target_c)){ 
                if (row > target_r){
                        new_row--;
                } else if (row < target_r){
                        new_row++;
                }
                if (board[new_row][new_col] != ASTEROIDS)
                        row = new_row;
        } else {
                if (col > target_c){
                        new_col--;
                } else if (col < target_c){
                        new_col++;
                }
                if (board[new_row][new_col] != ASTEROIDS)
                        col = new_col;
        }
        place_on_board(board);
        return (target_r == row && target_c == col);
}

// Place asteroid on board
void Asteroid::place_on_board(char board[ROWS][COLS])
{
        if (board[row][col] != ASTEROIDS)
                board_char = board[row][col];       
        board[row][col] = ASTEROIDS;
}

// Check for asteroid at a location
bool Asteroid::check(int r, int c)
{
        return ((r == row) && (c == col));
}
