#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int total;
	cin >> total;

	vector<string> words;
	for (int i = 0; i < total; i++) {
		string buffer;
		cin >> buffer;
		words.push_back(buffer);
	}

	string order;
	cin >> order;

	cout << isAlienSorted(words, order) << endl;
	return 0;
}

// https://leetcode.cn/problems/verifying-an-alien-dictionary/		ÄÑ¶È·Ö£º1300