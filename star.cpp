// Star class functions

#include <iostream>
using namespace std;

#include "star.h"
#include "constants.h"

// Initialising the constants of Star class
Star::Star()
{
          center();
          alive = true;
          score = 0;
          num_moves = 0;
          dots_eaten = 0;
}

// Placing star at the center
void Star::center()
{
          row = MidRow;
          col = MidCol;
}

// Move the star
bool Star::move(char board[ROWS][COLS], char command)
{
          bool ate_dot = false;
          if (!boulder_ahead(board, command)){
                board[row][col] = SPACE;
                if (command == CMD_UP){
                        if (row == 0) {row = ROWS-1;} else {row--;}
                } else if (command == CMD_DOWN){
                        if (row == ROWS-1) {row = 0;} else {row++;}
                } else if (command == CMD_RIGHT){
                        if (col == COLS-1) {col = 0;} else {col++;}
                } else if (command == CMD_LEFT){
                        if (col == 0) {col = COLS-1;} else {col--;}
                }
        }
        if (board[row][col] == ASTEROIDS)
                die();
        if (board[row][col] == DOTS){
                ate_dot = true;
                dots_eaten++;
        }
        return ate_dot;
}

// Place the star on board
void Star::place_on_board(char board[ROWS][COLS])
{
        board[row][col] = STAR;
}

// Get number of moves
int Star::get_num_moves()
{
        return num_moves;
}

// Set column
void Star::set_col(int new_column)
{
        col = new_column;
}

// Set row
void Star::set_row(int new_row)
{
        row = new_row;
}

// Get star's column
int Star::get_col()
{
        return col;
}

// Get star's row
int Star::get_row()
{
        return row;
}
// Kill the star
void Star::die()
{
        alive = false;
}


// Check if star is present at the location
bool Star::check(int r, int c)
{
        return (r==row && c==col);
}

// Add to the score
void Star::add_to_score(int n)
{
        score+=n;
}

// Get the score
int Star::get_score()
{
        return score;
}

// Check if star is alive or dead
bool Star::is_alive()
{
        return alive;
}

// Set number of dots eaten
 void Star::set_dots(int new_eaten)
{
        dots_eaten = new_eaten;
}

// Get the number of dots eaten
 int Star::get_dots()
{
        return dots_eaten;
}

// Check for boulder
bool Star::boulder_ahead(char board[ROWS][COLS], char command)
{
        if (command == CMD_UP){
                if (row == 0){
                        return (board[ROWS-1][col] == BOULDER);
                } else {
                        return (board[row-1][col] == BOULDER);
                }
        } else if (command == CMD_DOWN){
                if (row == ROWS-1){
                        return (board[0][col] == BOULDER);
                } else {
                        return (board[row+1][col] == BOULDER);
                }
        } else if (command == CMD_RIGHT){
                if (col == COLS-1){
                        return (board[row][0] == BOULDER);
                } else {
                        return (board[row][col+1] == BOULDER);
                }
        } else if (command == CMD_LEFT){
                if (col == 0){
                        return (board[row][COLS-1] == BOULDER);
                } else {
                        return (board[row][col-1] == BOULDER);
                }
        }
        return true;
}
