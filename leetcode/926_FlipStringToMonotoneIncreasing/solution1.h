#pragma once

#include <iostream>
using namespace std;

int minFlipsMonoIncr(string s) {
	int left = 0;
	int right = s.length() - 1;
	int zeros = 0, ones = 0;
	while (left<s.size() && s[left] - 48 != 1) left++;
	while (right>=0 && s[right] - 48 != 0) right--;

	for (int i = left; i <=right; i++) {
		if (s[i] - 48) ones++;
		else zeros++;
	}
	return zeros < ones ? zeros : ones;
}

// 运行结果：解答错误
// 思路不是很对。虽然能过样例，但是s="10011111110010111011"时输出的值为6，答案是5
// 因为这一算法默认的是全改一个数，比如全改1或全改0。