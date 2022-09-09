#ifndef Player_h
#define Player_h

#include "Player.h"
using namespace std;

class Player {
public:
	string name;
	int position;
	void initPlayer(string);
	int getCurrentPosition();
	void incPos(int, int);
};

#endif