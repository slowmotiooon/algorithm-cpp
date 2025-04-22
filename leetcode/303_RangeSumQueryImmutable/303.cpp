#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int total;
	cin >> total;

	vector<int> nums;
	for (int i = 0; i < total; i++) {
		int buffer;
		cin >> buffer;
		nums.push_back(buffer);
	}

	NumArray* n1 = new NumArray(nums);

	while (1) {
		int left, right;
		cin >> left;
		if (left == -1) break;
		cin >> right;
		cout << n1->sumRange(left, right);
	}

	return 0;
}