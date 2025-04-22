#pragma once

#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	auto p1 = lower_bound(nums.begin(), nums.end(), target);
	auto p2 = upper_bound(nums.begin(), nums.end(), target);
	if (p1==p2) return { -1,-1 };
	int a = p1 - nums.begin();
	int b = p2 - nums.begin()-1;
	return { a,b };
}

// Í¨¹ı | 6ms | 15.92MB
// O(logn) | O(1)