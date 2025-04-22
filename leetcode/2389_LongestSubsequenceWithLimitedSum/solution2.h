#pragma once

#include <vector>
#include <algorithm>
using namespace std;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
	sort(nums.begin(), nums.end());
	for (int i = 1; i < nums.size(); i++) nums[i] += nums[i - 1];
	vector<int> result;

	for (int x : queries) {
		int left = 0, right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > x) right = mid;
			else left = mid + 1;
		}
		result.push_back(right);
	}
	return result;
}

// 通过 | 13ms | 16.25MB
// O((n+m)*log(m)) | O(1) 在不改变nums数组的情况下需要O(n)
// 需要把nums排序，转换为其前缀和后再使用二分查找