// Terminal functions

#ifndef TERMFUNCS_H
#define TERMFUNCS_H

const char      KEY_UP    = 130;
const char      KEY_DOWN  = 131;
const char      KEY_LEFT  = 132;
const char      KEY_RIGHT = 133;
const char      ESCAPE    = 27;

#include <string>

using std::string;

char getachar();
char getacharnow(int);
void screen_clear();
void screen_home();

int  random_int(int, int);
void seed_random(int);

#endif
