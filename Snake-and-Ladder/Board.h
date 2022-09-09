#ifndef Board_H
#define Board_H

#include "Board.h"
#include<bits/stdc++.h>
#include "Cell.h"
#include "getRand.h"

using namespace std;

class Board {
public:

	vector<vector<Cell>> B;
	map<int, int> snakes, ladder;

	void initializeBoard(int, getRand &);
	void addSnakesAndLadders(int, getRand &);

};


#endif