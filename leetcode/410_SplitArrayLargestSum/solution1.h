#pragma once

#include <vector>
using namespace std;

int splitArray(vector<int>& nums, int k) {
	vector<int> sums(nums.size());
	sums[0] = nums[0];
	for (int i = 1; i < sums.size(); i++) sums[i] += sums[i - 1] + nums[i];
	
	int m = sums[sums.size() - 1] / k;

	if (k == 1) return sums[sums.size() - 1];
	vector<int> answers = {0};
	vector<int>::iterator it = sums.begin();
	for (int i = 1; i < k; i++) {
		auto mid = lower_bound(it, sums.end(), i * m);
		if (mid != sums.begin()) {
			vector<int>::iterator mid2 = mid - 1;
			if (*mid - i*m > i*m - *mid2) mid = mid2;
		}
		answers.push_back(*mid-answers.back());
		it = mid + 1;
	}
	answers.push_back(*(sums.end() - 1) - *(it - 1));
	return *max_element(answers.begin(), answers.end());
}

// 解答错误
// 只能过测试样例。算法本身不正确
