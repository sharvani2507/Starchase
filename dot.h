// Dot Class

#ifndef DOT_H_INCLUDED
#define DOT_H_INCLUDED

#include "constants.h"

class Dot {
        public:
                Dot();
                
                // Location for the dot
                void set_random_location(char[ROWS][COLS]);
                
                //Place the dot on board
                void place_on_board(char[ROWS][COLS]);
                
                // Check for presence of the dot
                bool check(int, int);
                
                // Sets eaten 
                void set_eaten(bool);
                
                // Returns whether eaten or not
                bool was_eaten();
                
        private:
                int row, col;
                bool eaten;
                
};

#endif
