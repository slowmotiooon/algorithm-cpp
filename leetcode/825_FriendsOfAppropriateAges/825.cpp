#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> ages(n);
	for (int& i : ages) cin >> i;

	cout << numFriendRequests(ages) << endl;
	return 0;
}

// https://leetcode.cn/problems/friends-of-appropriate-ages/description/		1697