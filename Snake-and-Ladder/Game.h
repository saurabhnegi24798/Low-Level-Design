#ifndef Game_h
#define Game_h

#include "Player.h"
#include "Board.h"
#include "Game.h"


class Game {
public:
	vector<Player> Players;
	void startGame();
	void displayWinner(Player &);
	int initBoard(Board &, getRand &);
	int inputPlayers();
};

#endif