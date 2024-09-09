// Terminal functions

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <ctype.h>
using namespace std;
#include "termfuncs.h"

static const string CSI = "\033[";

static termios prev_tty_state;
static int prev_state_stored = 0;

static char handle_escape_seq();

char getachar()
{
	char q_key = 0;
	char *qk = NULL;
	char c;
	int  nread;

	if ( ( qk = getenv("TF_QUIT") ) != NULL ){
		q_key = qk[0];
	}
	cout << std::flush;
	if ( isatty(0) ){
		struct termios	info, orig;
		
		tcgetattr(0, &info);
		orig = info;
		prev_tty_state = orig;
		prev_state_stored = 1;

		info.c_lflag &= ~ECHO;
		info.c_lflag &= ~ICANON;
		tcsetattr(0, TCSANOW, &info);

		nread = read(0, &c, 1);
		if ( nread == 1 && c == ESCAPE )
			c = handle_escape_seq();

		tcsetattr(0, TCSANOW, &orig);
	}
	else {
		if ( cin.get(c) )
			nread = 1;
		else
			nread = 0;
			
		if ( nread == 0 && qk != NULL )
			exit(0);
	}

	if ( nread == 1 && qk != NULL && c == q_key ){
		exit(0);
	}

	return ( nread > 0 ? c : 0 );
}

char getacharnow(int decisecs)
{
	char c;

	cout << std::flush;
	if ( isatty(0) ) 
	{
		struct termios	info, orig;
		
		tcgetattr(0, &info);
		orig = info;
		prev_tty_state = orig;
		prev_state_stored = 1;

		info.c_lflag &= ~ECHO;
		info.c_lflag &= ~ICANON;
		info.c_cc[VMIN] = 0;
		info.c_cc[VTIME] = decisecs;
		tcsetattr(0, TCSANOW, &info);

		if ( read(0, &c, 1) == 1 ){
			if ( c == ESCAPE )
				c = handle_escape_seq();
		}
		else
			c = '\0';

		tcsetattr(0, TCSANOW, &orig);
		
	}
	else {
		if ( read(0, &c, 1) != 1 )
			c = '\0';
	}

	return (int) c;
}

char handle_escape_seq()
{
	struct termios	info, orig;
	char		buf[100];
	int		pos = 0;
	char		c;
	void		(*oldhand)(int);

	if ( !isatty(0) ) 
		return ESCAPE;

	oldhand = signal(SIGINT, SIG_IGN);

	tcgetattr(0, &info);
	orig = info;

	info.c_lflag &= ~ECHO;
	info.c_lflag &= ~ICANON;
	info.c_cc[VMIN] = 0;
	info.c_cc[VTIME] = 1;
	tcsetattr(0, TCSANOW, &info);

	do
	{
		if ( read(0, &c, 1) == 1 )
			buf[pos++] = c;
		else
			break;
	}
	while( !isalpha((int)c) && pos < 99 );

	if ( pos == 0 || (buf[0] != '[' && buf[0] != 'O' ) )
		c = ESCAPE;
	else 
		switch(buf[1]){
			case 'A':		c = KEY_UP;	break;
			case 'B':		c = KEY_DOWN;	break;
			case 'C':		c = KEY_RIGHT;	break;
			case 'D':		c = KEY_LEFT;	break;
			default :
						c = ESCAPE;
		}

	tcsetattr(0, TCSANOW, &orig);
	signal(SIGINT, oldhand);
	return c;
}

void screen_clear()
{
	cout << (CSI + "H");
	cout << (CSI + "2J");
}

void screen_home()
{
	cout << (CSI + "H");
}

static int rand_seed = -1;

void seed_random(int s)
{
	if ( s > 0 ) {
		srand(s);
		rand_seed = s;
	}
}

int random_int(int lo, int hi)
{
	int	range = hi - lo + 1;
	char	*seed_str;

	if ( rand_seed == -1 ) {
		seed_str = getenv( "SNAKE_SEED" );
		if ( seed_str != NULL )
			seed_random( (unsigned) atoi(seed_str) );
		else 
			seed_random( (unsigned) time(NULL) );
	}
	if ( range <= 0 )
		return 17;

	return lo + ( rand() % range );
}

