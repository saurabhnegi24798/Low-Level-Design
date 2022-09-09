#include<bits/stdc++.h>
#include "getRand.h"

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand::getRnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
