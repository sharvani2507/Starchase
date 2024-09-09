// Defining required constants 

#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

// Rows and Columns
const int ROWS    = 21;
const int COLS    = 61;
const int MidRow  = ROWS/2;
const int MidCol  = COLS/2;

// Borders
const char BOTTOM_BORDER = '-', TOP_BORDER = '-';
const char CORNER_BORDER = '+';
const char SIDE_BORDER   = '|';

// Characters
//const char BLACKHOLE = '@';
const char ASTEROIDS = '!';
const char DOTS      = 'O';
const char BOULDER   = 'X';
const char SPACE     = ' ';
const char STAR      = '*';

// Objects
const int NUM_ASTEROIDS         = 4;
const int NUM_LEVELS            = 10;
const int DOTS_PER_LEVEL        = 5;
const int NUM_DOTS              = DOTS_PER_LEVEL * NUM_LEVELS;
const int BOULDERS_PER_LEVEL    = 1;
const int NUM_BOULDERS          = BOULDERS_PER_LEVEL * NUM_LEVELS;
//const float BLACKHOLE_PER_LEVEL = 1/3;
//const int NUM_BLACKHOLE         = BLACKHOLE_PER_LEVEL * NUM_LEVELS;

const int MIN_BOULDER_WIDTH  = COLS / 10;
const int MAX_BOULDER_WIDTH  = COLS / 4;
const int MIN_BOULDER_HEIGHT = ROWS / 10;
const int MAX_BOULDER_HEIGHT = ROWS / 4;

// Rewards
const int DOT_REWARD   = 1;
const int LEVEL_REWARD = 10;

// Commands
const char CMD_UP    ='w';
const char CMD_DOWN  ='s';
const char CMD_LEFT  ='a';
const char CMD_RIGHT ='d';
const char CMD_QUIT  ='q';
const char CHEAT     = 'G';
const char LEFT      = '>';
const char RIGHT     = '<';
const char UP        = '^';
const char DOWN      = 'v';

// Game Speed
const int CHASE = 2;
const int SPEED = 3;

#endif
