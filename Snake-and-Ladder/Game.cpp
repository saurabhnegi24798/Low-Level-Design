#include<bits/stdc++.h>
#include "Game.h"
#include "Player.h"
#include "Dice.h"
#include "Board.h"
#include "getRand.h"

using namespace std;

void Game::startGame() {

	getRand G;

	Board B;
	int sz = initBoard(B, G);

	int numOfPlayers = inputPlayers();

	Dice D;

	int currentPlayerIndex = 0;

	while (1) {
		currentPlayerIndex %= numOfPlayers;
		int diceNum = D.rollDice(G);
		assert(diceNum >= 1 and diceNum <= 6);
		cout << "Chance of " << Players[currentPlayerIndex].name << " and dice shows " << diceNum << " after rolling" << '\n';

		Players[currentPlayerIndex].incPos(diceNum, sz);
		if (diceNum == 6) {
			cout << "Rolling Again....." << '\n';
			continue;
		};

		if (B.ladder.find(Players[currentPlayerIndex].getCurrentPosition()) != B.ladder.end()) {
			cout << "Wohoo " << Players[currentPlayerIndex].name << " You Find a ladder at position " << Players[currentPlayerIndex].getCurrentPosition() << '\n';
			int ladderTop = B.ladder[Players[currentPlayerIndex].getCurrentPosition()];
			Players[currentPlayerIndex].incPos(ladderTop - Players[currentPlayerIndex].getCurrentPosition(), sz);
			assert(Players[currentPlayerIndex].getCurrentPosition() == ladderTop);
		} else if (B.snakes.find(Players[currentPlayerIndex].getCurrentPosition()) != B.snakes.end()) {
			int snakeBottom = B.snakes[Players[currentPlayerIndex].getCurrentPosition()];
			cout << "Oops " << Players[currentPlayerIndex].name << " You Find a Snake at position " << Players[currentPlayerIndex].getCurrentPosition() << '\n';
			Players[currentPlayerIndex].incPos(snakeBottom - Players[currentPlayerIndex].getCurrentPosition(), sz);
			assert(Players[currentPlayerIndex].getCurrentPosition() == snakeBottom);
		}

		cout << "Now " << Players[currentPlayerIndex].name << " is at position " << Players[currentPlayerIndex].getCurrentPosition() << '\n';

		// winning condition
		if (Players[currentPlayerIndex].getCurrentPosition() == sz * sz + 1) {
			break;
		}
		assert(Players[currentPlayerIndex].getCurrentPosition() >= 1);
		assert(Players[currentPlayerIndex].getCurrentPosition() <= sz * sz);

		currentPlayerIndex++;
	}

	displayWinner(Players[currentPlayerIndex]);
}

int Game::initBoard(Board &B, getRand &G) {
	cout << "Enter Board Size N x N" << '\n';
	int sz;
	cin >> sz;
	B.initializeBoard(sz, G);
	return sz;
}

int Game::inputPlayers() {
	string Name;
	cout << "Enter Number of Players " << '\n';
	int numOfPlayers;
	cin >> numOfPlayers;

	Players.resize(numOfPlayers);

	for (int i = 0; i < numOfPlayers; i++) {
		cout << "Enter the name of " << i + 1 << " Player" << '\n';
		cin >> Name;
		Players[i].initPlayer(Name);
	}
	return numOfPlayers;
}


void Game::displayWinner(Player &player) {
	cout << "Congratulations " << '\n';
	cout << player.name << " on winning the game " << '\n';
}
