#pragma once

#include <iostream>
#include <cmath>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int count[128] = { 0 };
	int maxv = 0;

	int l = -1;

	for (int i = 0; i < s.size(); i++) {
		if (count[s[i]] != 0) l = max(count[s[i]] - 1,l);	//使用max避免左索引向左走
		count[s[i]] = i + 1;
		maxv = max(maxv, i - l );
	}

	return maxv;
}

// 运行结果：
// 通过 | 3ms | 10.52MB
// 依照题解 https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/2361797/3-wu-zhong-fu-zi-fu-de-zui-chang-zi-chua-26i5/?envType=study-plan-v2&envId=top-100-liked
// 方法为滑动窗口