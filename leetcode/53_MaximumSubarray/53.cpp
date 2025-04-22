#include <iostream>
#include "solution3.h"
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

	cout << betterMaxSubArray(nums) << endl;
	return 0;
}