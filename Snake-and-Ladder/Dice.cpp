#include<bits/stdc++.h>
#include "Dice.h"
#include "getRand.h"

int Dice::rollDice(getRand &G) {
	int diceRes = G.getRnd(1, 6);
	return diceRes;
}