#include<iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> piles(n);
	for (int& i : piles) cin >> i;

	int h;
	cin >> h;

	cout << minEatingSpeed(piles, h) << endl;
	return 0;
}

// https://leetcode.cn/problems/koko-eating-bananas/description/		1766