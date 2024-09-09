// Boulder class functions

#include <iostream>
#include "boulder.h"
using namespace std;

// Initialising the constants of Boulder class
Boulder::Boulder()
{
    do {
        top_left_r = random_int(0, ROWS-1);
        top_left_c = random_int(0, COLS-1);
        height = random_int(MIN_BOULDER_HEIGHT, MAX_BOULDER_HEIGHT);
        width  = random_int(MIN_BOULDER_WIDTH, MAX_BOULDER_WIDTH);
    } while (overlap_middle());
    
    row = 0;
    col = 0;
}

// Place boulder on board
void Boulder::place_on_board(char board[ROWS][COLS])
{
        for (int r = top_left_r; r <= top_left_r + height; r++) {
                for (int c = top_left_c; c <= top_left_c + width; c++) {
                        if (r < ROWS && c < COLS) {
                                board[r][c] = BOULDER;
                        }
                }
        }
}

// Check for overlap with middle
bool Boulder::overlap_middle()
{
    bool center_row = (ROWS / 2) >= top_left_r && (ROWS / 2) <= (top_left_r + height);
    bool center_col = (COLS / 2) >= top_left_c && (COLS / 2) <= (top_left_c + height);

    return (center_row && center_col);
}

