#include <iostream>
#include "solution3.h"
using namespace std;

int main() {
	int total;
	cin >> total;

	vector<int> nums;

	for (int i = 0; i < total; i++) {
		int b;
		cin >> b;
		nums.push_back(b);
	}

	int k;
	cin >> k;

	rotate(nums, k);

	for (int i : nums) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}