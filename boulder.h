// Boulder class

#ifndef BOULDER_H_INCLUDED
#define BOULDER_H_INCLUDED

#include "constants.h"
#include "termfuncs.h"

class Boulder{
            public:
                   Boulder();
                   
                   // Place boulder on board
                   void place_on_board(char[ROWS][COLS]);                  
                   

                                     
            private:
                   int top_left_r, top_left_c, height, width;
                   int row, col;

                   // Boulder location check;
                   bool overlap_middle();                  
};

#endif
