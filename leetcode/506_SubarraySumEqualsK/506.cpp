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

	int k;
	cin >> k;

	cout << subarraySum(nums, k) << endl;
	return 0;
}