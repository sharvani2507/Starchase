#include <iostream>
using namespace std;

#include "game.h"
#include "star.h"
#include "asteroids.h"
#include "dot.h"
#include "termfuncs.h"
#include "constants.h"

// Initialising constants
Game::Game()
{
    level = 1;
    level_over = false;
    game_won = false;

}

// Print the manual
void Game::print_manual()
{
    screen_clear();
    cout << ""
            "          \n"
            " Move left:    " << CMD_LEFT << "\n"
            " Move right:   " << CMD_RIGHT << "\n"
            " Move up:      " << CMD_UP  << "\n"
            " Move down:    " << CMD_DOWN << "\n"
            "\n"
            " Collect all the dots. They look like: " << DOTS << "\n"
            " Avoid the asteroids. They look like: " << ASTEROIDS << "\n"
            "\n"
            " Good luck!\n"
            "\n"
            " Press any key to continue...\n";

    getachar();
}

// Run the game
void Game::run()
{
    while (!game_won && s.is_alive()){
        reset_level();
        start_level();
        play_level();
        if(s.is_alive()){
            complete_level();
        }
    }
    if (game_won){
        cout << "You win!!\n";
    } else {
        cout << "Well, try again :(\n";
    }
}

// Clear the board
void Game::clear_board()
{
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            board[r][c] = SPACE;
        }
    }
}

// Print the board
void Game::print_board()
{
    for (int r = -1; r <= ROWS; r++){
        for (int c = -1; c <= COLS; c++){
            if ((r == -1 || r == ROWS) || (c == -1 || c == COLS)){
                cout << border(r, c);
            } else {
                cout << board[r][c];
            }
        }
        cout << endl;
    }
    cout << "Score: " << s.get_score() << endl;
}

// Border
char Game::border(int row, int col)
{
    if (row == -1 || row == ROWS){
        if (col == -1 || col == COLS){
            return CORNER_BORDER;
        } else {
            return TOP_BORDER;
        }
    } else {
        return SIDE_BORDER;
    }
}

// Setting the boulders
void Game::set_boulders()
{
        for (int i=0; i<BOULDERS_PER_LEVEL*level; i++)
                boulders[i].place_on_board(board);
}

// Setting locations for the dots
void Game::init_dots()
{
        set_boulders();
        for (int i=0; i<DOTS_PER_LEVEL*level; i++){
                dots[i].set_random_location(board);
                dots[i].set_eaten(false);
                dots[i].place_on_board(board);
        }
}

// Place the dots on board
void Game::set_dots()
{
        for (int i=0; i<DOTS_PER_LEVEL*level; i++)
                dots[i].place_on_board(board);
}

// Eats the dot
void Game::eat_dots(int r, int c)
{
        for (int i=0; i<DOTS_PER_LEVEL*level; i++)
                if (dots[i].check(r,c))
                        dots[i].was_eaten();
        s.add_to_score(DOT_REWARD);
}

// Set Asteroids
void Game::set_asteroids()
{
        for (int i=0; i<NUM_ASTEROIDS; i++){
                if (i==0){
                        aster[i].set_location(0,0);
                } else if (i==1){
                        aster[i].set_location(0,COLS-1);
                } else if (i==2){
                        aster[i].set_location(ROWS-1,0);
                } else if (i==3){
                        aster[i].set_location(ROWS-1,COLS-1);
                } else {
                        aster[i].set_random_location();
                }
                aster[i].place_on_board(board);
        }
}

// Reset level
void Game::reset_level()
{
    clear_board();
    init_dots();
    set_boulders();
    set_asteroids();
    s.center();
    s.place_on_board(board);
    s.set_dots(0);
    level_over = false;
}

// Start level
void Game::start_level()
{
    screen_clear();
    print_board();
    cout << "Level " << level << ": Press any key to start\n";
    getachar();
    screen_clear();
    print_board(); 
}

// Play level
void Game::play_level()
{
    char move;
    while (s.is_alive() && !level_over){
        move = getacharnow(2);
        if (move == CMD_QUIT){
            level_over = true;
            s.die();
            return;
        } else if (move == CHEAT){
            level_over = true;
        }
        if (s.move(board, move)){
            eat_dots(s.get_row(), s.get_col());
            level_over = !(s.get_dots() < DOTS_PER_LEVEL);
            level++;
        }
        if (s.is_alive())   
            s.place_on_board(board);
        screen_home();
        print_board();
        
        if (s.get_num_moves() % CHASE == 0 && !level_over){
            for (int i = 0; i < NUM_ASTEROIDS; i++){
                if (aster[i].move(board, s.get_row(), s.get_col()))
                    s.die();
                aster[i].place_on_board(board);
            }
        }
        screen_home();
        print_board();
    }
}

// Complete level
void Game::complete_level()
{
    s.add_to_score(LEVEL_REWARD);
    level++;
    game_won = level > NUM_LEVELS;
}

