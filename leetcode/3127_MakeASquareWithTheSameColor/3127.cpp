#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	vector<vector<char>> grid(3);
	for (int i = 0; i < 3; i++) {
		vector<char> line(3);
		cin >> line[0] >> line[1] >> line[2];
		grid[i] = line;
	}
	cout << canMakeSquare(grid) << endl;
	return 0;
}

// https://leetcode.cn/problems/make-a-square-with-the-same-color/description/?envType=daily-question&envId=2024-08-31		1338
// tag: #matrix 