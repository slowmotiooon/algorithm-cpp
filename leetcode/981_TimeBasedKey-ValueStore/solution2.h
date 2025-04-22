#pragma once

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class TimeMap {
public:
	unordered_map<string, vector<pair<int, string>>> m;

	TimeMap() {
		m = {};
	}

	void set(string key, string value, int timestamp) {
		m[key].push_back({ timestamp,value });
	}

	string get(string key, int timestamp) {
		if (m.find(key) == m.end()) return "";
		auto left = m[key].begin();
		auto right = m[key].end();
		while (left < right) {
			auto mid = left + (right - left) / 2;
			if (mid->first >= timestamp) right = mid;
			else left = mid + 1;
		}
		if (right == m[key].begin() && right->first > timestamp) return "";
		else if (right == m[key].end() || right->first > timestamp) return (--right)->second;
		else return right->second;
	}
};

// 通过 | 283ms | 130.61MB
// 转换了一下存储数据的方式，这个比较好写一些。