// Asteroids Class

#ifndef ASTEROID_H_INCLUDED
#define ASTEROID_H_INCLUDED

#include "constants.h"

class Asteroid{
         public:
                 Asteroid();
                 
                 // Set location
                 void set_location(int r, int c);
                 void set_random_location();
                 
                 // Chase algorithm
                 bool move(char[ROWS][COLS], int target_r, int target_c);
                 
                 // Place the asteroid on the board
                 void place_on_board(char[ROWS][COLS]);
                 
                 // Check for the presence of asteroid at the point
                 bool check(int, int);
                 
         private: 
                 int row, col;
                 char board_char;
                 
};

#endif
