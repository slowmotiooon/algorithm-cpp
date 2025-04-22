#include <iostream>
#include "solution2.h"
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

	vector<int> result = productExceptSelf(nums);

	for (int i : result) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}