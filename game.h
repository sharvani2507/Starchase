#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "constants.h"
#include "star.h"
#include "asteroids.h"
#include "dot.h"
#include "boulder.h"

class Game{
    public:
        Game();
        
        // Print manual and take user's input
        void print_manual();
        
        // Run the game 
        void run();
        
    private:
        char board[ROWS][COLS];
        int  level;
        bool level_over;
        bool game_won;
        
        Star s;
        Asteroid aster[NUM_ASTEROIDS];
        Dot dots[NUM_DOTS];
        Boulder boulders[NUM_BOULDERS];
        
        // Clean the board
        void clear_board();
        
        // Print the board
        void print_board();
        char border(int, int);
        
        // Set the boulders
        void set_boulders();
        
        // Set the dots
        void init_dots();
        void set_dots();
        void eat_dots(int, int);
        
        // Set the asteroids
        void set_asteroids();
        
        // Gameplay
        void reset_level();
        void start_level();
        void play_level();
        void complete_level();
        
};

#endif

