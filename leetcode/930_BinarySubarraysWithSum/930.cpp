#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int& i : nums) cin >> i;
	
	int goal;
	cin >> goal;
	cout << numSubarraysWithSum(nums, goal) << endl;
	return 0;
}

// https://leetcode.cn/problems/binary-subarrays-with-sum/description/