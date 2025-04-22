#pragma once

#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
	k = k % nums.size();
	reverse(nums.begin(), nums.end());

	auto it = nums.begin();
	while (k > 0) {
		it++;
		k--;
	}
	reverse(nums.begin(), it);
	reverse(it, nums.end());
}

// 运行结果：
// 通过 | 28ms | 26.94MB
// O(n) | O(1)
// 思路来源：https://leetcode.cn/problems/rotate-array/solutions/2784427/tu-jie-yuan-di-zuo-fa-yi-tu-miao-dong-py-ryfv
// 做法：先反转整个数组，再反转前k个，最后反转后n-k个
// 示例：1 2 3 | 4 5 6 7		k=3
// 1.   7 6 5 | 4 3 2 1
// 2.   5 6 7 | 4 3 2 1
// 3.	5 6 7 | 1 2 3 4		结束
// 一下是优化后的算法，把while(k>0)循环省略，加快速度。

void betterRotate(vector<int>& nums, int k) {
	k %= nums.size(); // 轮转 k 次等于轮转 k%n 次
	reverse(nums.begin(),nums.end());	
	reverse(nums.begin(), nums.begin() + k);	//简化了通过while计算k对应迭代器的过程
	reverse(nums.begin() + k, nums.end());
}
