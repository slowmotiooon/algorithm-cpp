#pragma once

#include <string>
#include <unordered_map>
using namespace std;

int maximumLength(string s) {
	int n = s.length();
	unordered_map<string, int> count;
	int left = 1, right = n-2;
	while (left <= right) {
		count.clear();
		int mid = left + (right - left) / 2;
		for (int i = 0; i <= n - mid; i++) {
			count[s.substr(i, mid)]++;
		}
		bool checked = false;
		for (auto i : count) {
			if (i.second >= 3) {
				checked = true;
				break;
			}
		}
		if (checked) left = mid + 1;
		else right = mid - 1;
	}
	return right ? right : -1;
}

// 超出时间限制
// 大概率只是效率不高