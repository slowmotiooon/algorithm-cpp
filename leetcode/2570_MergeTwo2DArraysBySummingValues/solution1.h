#pragma once

#include <vector>
using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
	vector<vector<int>> result;
	int p1 = 0, p2 = 0;
	while (p1 < nums1.size() && p2 < nums2.size()) {
		if (nums1[p1][0] < nums2[p2][0]) {
			result.push_back(nums1[p1]);
			p1++;
		}
		else if (nums1[p1][0] > nums2[p2][0]) {
			result.push_back(nums2[p2]);
			p2++;
		}
		else {
			result.push_back({ nums1[p1][0],nums1[p1][1] + nums2[p2][1] });
			p1++;
			p2++;
		}
	}
	for (; p1 < nums1.size(); p1++) result.push_back(nums1[p1]);
	for (; p2 < nums2.size(); p2++) result.push_back(nums2[p2]);
	return result;
}

// Í¨¹ý | 13ms | 13.44MB
// O(n+m) | O(1)