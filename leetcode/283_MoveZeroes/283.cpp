#include <iostream>
#include "solution4.h"
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

	moveZeroes(nums);

	for (int i : nums) {
		cout << i << ' ';
	}
	cout << endl;

	return 0;
}