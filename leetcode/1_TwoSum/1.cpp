#include <iostream>
#include "solution4.h"
// #include <unordered_map>
using namespace std;

int main() {
	int total;
	cin >> total;

	vector<int> nums;
	for (size_t i = 0; i < total; i++)
	{
		int buffer;
		cin >> buffer;
		nums.push_back(buffer);
	}

	int target;
	cin >> target;

	vector<int> result = twoSum(nums, target);

	for (int item : result) {
		cout << item << " ";
	}
	cout << endl;

	return 0;
}