#include<bits/stdc++.h>
#include "Player.h"

void Player::initPlayer(string n) {
	name = n;
	position = 0;
}

int Player::getCurrentPosition() {
	return position;
}

void Player::incPos(int x, int sz) {
	if (position + x <= ((sz * sz) + 1)) {
		position += x;
	}
}