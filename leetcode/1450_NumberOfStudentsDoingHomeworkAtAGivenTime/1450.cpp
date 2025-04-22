#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> startTime(n), endTime(n);
	for (int& i : startTime) {
		cin >> i;
	}
	for (int& i : endTime) {
		cin >> i;
	}
	int queryTime;
	cin >> queryTime;
	cout << busyStudent(startTime, endTime, queryTime) << endl;
	return 0;
}

// https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/?envType=daily-question&envId=2024-09-01		1129