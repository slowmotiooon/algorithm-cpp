#pragma once

#include <vector>
using namespace std;

int trap(vector<int>& height) {
	int n = height.size();
	vector<int> preMax(n,0), sufMax(n,0);
	for (int i = 0; i < n; i++) preMax[i] = max((i == 0 ? 0 : preMax[i - 1]), height[i]);
	for (int i = n - 1; i >= 0; i--) sufMax[i] = max((i == n - 1 ? 0 : sufMax[i + 1]), height[i]);
	int ans = 0;
	for (int i = 0; i < n; i++) ans += min(preMax[i], sufMax[i]) - height[i];
	return ans;
}

// 通过 | 15ms | 25.25MB
// O(n) | O(n)
// 思路来自：https://leetcode.cn/problems/trapping-rain-water/solutions/1974340/zuo-liao-nbian-huan-bu-hui-yi-ge-shi-pin-ukwm 方法一
// 前后缀分解