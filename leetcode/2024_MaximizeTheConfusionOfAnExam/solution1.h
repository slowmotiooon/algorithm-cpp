#pragma once

#include <string>
using namespace std;

int maxConsecutiveAnswers(string answerKey, int k) {
	int n = answerKey.size();
	int changes = k;
	int max = 0;
	int left = 0;
	int i = 0;
	for (; i < n; i++) {
		if (answerKey[i] == 'F') changes--;
		if (changes >= 0) continue;
		if (max < i - left) max = i - left;
		while (changes < 0) {
			if (answerKey[left] == 'F') changes++;
			left++;
		}
	}
	if (max < i - left) max = i - left;
	changes = k;
	left = 0;
	for (i = 0; i < n; i++) {
		if (answerKey[i] == 'T') changes--;
		if (changes >= 0) continue;
		if (max < i - left) max = i - left;
		while (changes < 0) {
			if (answerKey[left] == 'T') changes++;
			left++;
		}
	}
	if (max < i - left) max = i - left;
	return max;
}

// 通过 | 34ms | 11.31MB
// O(n) | O(1)
// 变长滑动窗口
