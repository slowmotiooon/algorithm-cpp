#pragma once

#include <vector>
using namespace std;

class TimeMap {
public:
	vector<pair<int, pair<string, string>>> timeSet;

	TimeMap() {
		timeSet = {};
	}

	void set(string key, string value, int timestamp) {
		timeSet.push_back({ timestamp,{key,value} });
	}

	string get(string key, int timestamp) {
		auto left = timeSet.begin(), it = timeSet.end();
		if (timestamp < left->first) return "";
		while (left < it) {
			auto mid = left + (it - left) / 2;
			if (mid->first >= timestamp) it = mid;
			else left = mid + 1;
		}
		if (it != timeSet.end() && it->first == timestamp) {
			for (vector<pair<int, pair<string, string>>>::iterator a = it; a!=timeSet.end() && a->first == timestamp; a++) {
				if (a->second.first == key) return a->second.second;
			}
		}
		else it--;
		for (;; it--) {
			if (it->second.first == key) return it->second.second;
			if (it == timeSet.begin()) break;
		}
		return "";
	}
};

// Í¨¹ý | 278ms | 136.63MB
// O(n) | O(1) get
// O(n) | O(1) set