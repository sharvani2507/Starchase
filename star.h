// Star Class

#ifndef STAR_H_INCLUDED
#define STAR_H_INCLUDED

#include "constants.h"

class Star{
         public:
                Star();
                
                // Star to be placed at center
                void center();
                
                // Moving star according to the commands
                bool move(char[ROWS][COLS], char command);
                
                // Place star on board
                void place_on_board(char[ROWS][COLS]);
                
                // Location
                void set_col(int);               
                void set_row(int);
                int get_col();
                int get_row();
                bool check(int, int);
        
                // Score
                void add_to_score(int);
                int get_score();
                int get_num_moves();
                
                // Kill the star
                void die();
                
                // Alive or not
                bool is_alive();
                
                // Set and get dots
                void set_dots(int);
                int get_dots();
         
         private:
                bool alive;
                int row, col;
                int score;
                int num_moves;
                int dots_eaten;
                
                bool boulder_ahead(char[ROWS][COLS], char);
                
};

#endif       
                
