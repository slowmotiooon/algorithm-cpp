#pragma once

#include <vector>
using namespace std;

constexpr int max(int x, int y) {
	return x > y ? x : y;
}

int maxProfit(vector<int>& prices) {
	vector<int> dp = { 0 };
	int minPrice = 2147483647;

	for (int i = 0; i < prices.size(); i++) {
		if (prices[i] < minPrice) minPrice = prices[i];
		dp.push_back(max(dp[i], prices[i] - minPrice));
	}

	return dp[prices.size()];
}

// 运行结果：
// 通过 | 161ms | 103.62MB
// O(n) | O(n)
// 思路参照题解：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solutions/139559/gu-piao-wen-ti-python3-c-by-z1m 方法二
// 使用一维动态规划。
//		dp[i]指的是当前天数的最大利润
//		更新最大利润的方法是 dp.push_back(max(dp[i], prices[i] - minPrice));
//		最后的最大利润 dp[prices.size()] 即为要求的结果