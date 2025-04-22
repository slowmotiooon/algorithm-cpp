#pragma once

#include <vector>
#include <algorithm>
using namespace std;

int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
	int ans = 0;
	sort(staple.begin(), staple.end());
	sort(drinks.begin(), drinks.end());

	int right = drinks.size() - 1;

	for (int i : staple) {
		while (right >= 0 && i + drinks[right] > x) right--;
		ans = (ans + right + 1) % 1000000007;
	}
	return ans;
}

// Í¨¹ý | 330ms | 146.49MB
// O(n+m) | O(1)