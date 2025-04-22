#pragma once

#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> hashTable;
bool fitCondition() {
	for (auto it = hashTable.begin(); it != hashTable.end(); it++) {
		if (it->second > 2) return false;
	}
	return true;
}

int maximumLengthSubstring(string s) {
	int left = 0, right = 0;
	int max = 0;
	

	while (right < s.size() && left < s.size()) {
		if (fitCondition()) {
			hashTable[s[right]]++;
			right++;

		}
		while (!fitCondition()) {
			hashTable[s[left]] == 1 ? hashTable.erase(s[left]) : hashTable[s[left]]--;
			left++;
		}
		if (max < right - left) max = right - left;
	}
	return max;
}

// 通过 | 7ms | 10.12MB
// O(n) | O(m) m为哈希表数量