#pragma once

#include <vector>
#include <algorithm>
using namespace std;

int numFriendRequests(vector<int>& ages) {
	sort(ages.begin(), ages.end());
	int left1 = 0;
	int left2 = 0;
	int ans = 0;
	for (int i = 1; i < ages.size(); i++) {
		while (left1 < i && ages[left1] <= 0.5 * ages[i] + 7) left1++;
		while (left2 < i && (ages[left2] < ages[i] || ages[left1] <= 0.5 * ages[i] + 7)) left2++;
		ans += i - left1;
		ans += i - left2;
	}
	return ans;
}

// 通过 | 56ms | 40.23MB
// O(n) | O(1)
// 三指针