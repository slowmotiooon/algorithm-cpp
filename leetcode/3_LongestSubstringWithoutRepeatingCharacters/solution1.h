#pragma once

#include <iostream>
using namespace std;

void clear(int* list) {
	for (int i = 0; i < 128; i++) {
		list[i] = 0;
	}
}

int lengthOfLongestSubstring(string s) {
	int count[128];
	clear(count);
	int max = 0;

	for (int i = 0; s.size()-i>max; ) {	//剪枝，当i索引开始的字串长度小于max时，就没有必要重复了
		int current = 0;
		for (int j = i; j < s.size(); j++) {
			if (count[s[j]]==0) {
				count[s[j]] = j+1;
				current++;
			}
			else {
				i = count[s[j]];	//剪枝，把i++替换为这个语句可以把i定位到发生重复的字符后一个字符处，而不是简单的加一
				clear(count);
				break;
			}
		}
		if (current > max) max = current;
	}

	return max;
}

// 运行结果：
// 通过 | 12ms | 10.48MB
// 牛逼，一遍过。
// 时间复杂度达到了O(n^2)，但是疯狂剪枝。方法为遍历，还有优化空间。