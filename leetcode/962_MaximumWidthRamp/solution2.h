#pragma once

#include <vector>
#include <algorithm>
using namespace std;

int maxWidthRamp(vector<int>& nums) {
	vector<int> index(nums.size());
	for (int i = 1; i < nums.size(); i++) index[i] = index[i - 1] + 1;
	sort(index.begin(), index.end(), [&](int x, int y) {return nums[x] == nums[y] ? x > y:nums[x] > nums[y]; });
	int ans = 0;
	int minVal = index[0];
	for (int i : index) {
		ans = max(ans, i - minVal);
		minVal = min(minVal, i);
	}
	return ans;
}

// 通过 | 95ms | 33.05MB
// O(n*log(n)) | O(n)
// 思路来自：https://leetcode.cn/problems/maximum-width-ramp/solutions/2890680/pai-xu-er-fen-cha-zhao-dan-diao-zhan-by-m4ugu
// 排序之后就变成了 121.买卖股票的最佳时机 https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/ 了