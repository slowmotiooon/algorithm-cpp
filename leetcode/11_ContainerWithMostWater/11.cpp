#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int total;
	cin >> total;

	vector<int> heights;
	for (int i = 0; i < total; i++) {
		int buffer;
		cin >> buffer;
		heights.push_back(buffer);
	}

	cout << maxArea(heights) << endl;
	return 0;
}