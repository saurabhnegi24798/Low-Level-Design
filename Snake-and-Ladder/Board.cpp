#include<bits/stdc++.h>
#include "Board.h"
#include "Cell.h"
#include "getRand.h"

using namespace std;

void Board::initializeBoard(int sz, getRand &G) {
	B.resize(sz, vector<Cell> (sz));
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			B[i][j].initializeCell((i + 1) * sz + (j + 1));
		}
	}
	addSnakesAndLadders(sz, G);
}

void Board::addSnakesAndLadders(int sz, getRand &g) {

	// sz number of snakes will be added
	cout << "Snakes" << '\n';
	for (int i = 0; i < sz; i++) {
		int snakeStart = g.getRnd(sz + 1, sz * sz);
		int snakeEnd = g.getRnd(1, snakeStart - 1);
		cout << snakeStart << ' ' << snakeEnd << '\n';
		snakes[snakeStart] = snakeEnd;
	}

	// sz number of ladders will be added
	cout << "Ladders" << '\n';
	for (int i = 0; i < sz; i++) {
		int ladderStart = g.getRnd(1, sz * sz - sz);
		int ladderEnd = g.getRnd(ladderStart + 1, sz * sz);
		cout << ladderStart << ' ' << ladderEnd << '\n';
		ladder[ladderStart] = ladderEnd;
	}
}
