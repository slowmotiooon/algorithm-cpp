#pragma once

#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int minLengthAfterRemovals(vector<int>& nums) {
	int n = nums.size();
	int x = nums[n / 2];
	int range = upper_bound(nums.begin(), nums.end(), x) - lower_bound(nums.begin(), nums.end(), x);
	return max(range * 2 - n, n %2);
}

// 通过 | 117ms | 148.42MB
// O(logn) | O(1)
// 思路来源：https://leetcode.cn/problems/minimum-array-length-after-pair-removals/solutions/2446146/olog-n-tan-xin-er-fen-cha-zhao-pythonjav-t3qn
// 如何运用数组有序的特性？
// 那就是，只要数字的种类不是一种，那么最后一个元素一定大于第一个元素。如：1 1 1 1 1 2 2 2 2 2
// 因此，如果nums中所有的数字出现的次数都为1，那么就可以通过数次最后和最前相消，得到1或0。
// 但是有的数字会重复出现，这种情况只需要注意nums[n/2]处的数字的重复数量了。
// 因为按照最后最前相消的方法，nums[n/2]处是最后一个操作的，并且如果nums[n-2]的出现次数大于1的话，可能会出现同数相消的情况。
// 因此下一步就是确定nums[n/2]的范围，此时用到了二分查找。
// 之后的操作就可以参照链接中的解释了。