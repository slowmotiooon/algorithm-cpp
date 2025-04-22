#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> candies(n);
	for (int& i : candies) cin >> i;
	
	long long k;
	cin >> k;

	cout << maximumCandies(candies, k) << endl;
	return 0;
}

// https://leetcode.cn/problems/maximum-candies-allocated-to-k-children/description/		1646