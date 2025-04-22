#pragma once

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int f(string s) {
	char smallest = 'z';
	int count = 0;
	for (char c : s) {
		if (c < smallest) {
			smallest = c;
			count = 0;
		}
		if (c == smallest) count++;
	}
	return count;
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
	sort(words.begin(), words.end(), [&](string a, string b) {return f(a) < f(b); });
	vector<int> result;
	for (string s : queries) {
		int left = 0, right = words.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (f(words[mid]) > f(s)) right = mid;
			else left = mid + 1;
		}
		result.push_back(words.size() - right);
	}
	return result;
}

// 通过 | 28ms | 15.90MB
// O((m+n)*L*log(n)) L为字符串平均长度 | O(1)
// 排序+二分查找