#pragma once

#include <vector>
#include <unordered_set>
using namespace std;

int arithmeticTriplets(vector<int>& nums, int diff) {
	unordered_set<int> numSet;
	int ans = 0;
	for (int i : nums) numSet.insert(i);
	for (int i : nums) if (numSet.find(i - diff) != numSet.end() && numSet.find(i + diff) != numSet.end()) ans++;
	return ans;
}

// Í¨¹ý | 0ms | 11.44MB
// O(n) | O(n)