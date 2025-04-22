#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	vector<string> queries(n1), words(n2);
	for (string& s : queries) cin >> s;
	for (string& s : words) cin >> s;

	vector<int> result = numSmallerByFrequency(queries, words);
	for (int i : result) {
		cout << i << ", ";
	}
	cout << endl;
	return 0;
}

// https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/description/		1432