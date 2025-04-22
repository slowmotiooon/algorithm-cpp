#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	vector<vector<int>> intervals;

	int total;
	cin >> total;

	for (int i = 0; i < total; i++) {
		int a, b;
		cin >> a >> b;
		intervals.push_back({ a,b });
	}

	vector<vector<int>> result = merge(intervals);

	for (vector<int> i : result) {
		cout << i[0] << ' ' << i[1]<<',';
	}
	cout << endl;
	return 0;
}