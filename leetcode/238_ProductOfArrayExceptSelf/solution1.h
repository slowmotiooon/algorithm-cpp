#pragma once

#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	if (nums.size() == 2) return { nums[1],nums[0] };

	vector<int> frontSum(nums.size());
	vector<int> backSum(nums.size());
	vector<int> result(nums.size());

	for (int i = 0; i < nums.size(); i++) {
		if (i == 0) {
			frontSum[i] = nums[i];
			backSum[nums.size() - 1 - i] = nums[nums.size() - 1 - i];
		}
		else {
			frontSum[i] = frontSum[i - 1] * nums[i];
			backSum[nums.size() - 1 - i] = backSum[nums.size() - i] * nums[nums.size() - 1 - i];
			if (i == nums.size()-2) {
				result[0] = backSum[nums.size() - 1 - i];
				result[nums.size() - 1] = frontSum[nums.size()-2];
			}
		}
	}

	for (int i = 2; i < nums.size(); i++) {
		result[i - 1] = backSum[i] * frontSum[i - 2];
	}

	return result;
}

// 运行结果：
// 通过 | 53ms | 39.57MB
// O(n) | O(n)
// 依据提示1做出来的。具体思路如下：
// 示例：		2	3	4	5		答案：	60	40	30	24
// 前向前缀积：	2	6	24	120
//				\	\
//				    \	\
//						\	\
// 后向前缀积：	120	60	20	5
// 60和24已经出现，2*20=40，5*60=30		//我们发现frontSum[nums.size()-1]和backSum[0]没有用，说明还可以优化。

//优化后的算法（空间复杂度仍然是O(n)）：

vector<int> betterProductExceptSelf(vector<int>& nums) {
	int n = nums.size();
	vector<int> pre(n, 1);	//创建一个全部为1的数组
	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] * nums[i - 1];
	}

	vector<int> suf(n, 1);
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = suf[i + 1] * nums[i + 1];
	}

	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i] = pre[i] * suf[i];
	}
	return ans;
}

//作者：灵茶山艾府
//链接：https://leetcode.cn/problems/product-of-array-except-self/solutions/2783788/qian-hou-zhui-fen-jie-fu-ti-dan-pythonja-86r1/