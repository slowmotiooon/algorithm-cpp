#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	int total;
	cin >> total;

	vector<vector<int>> circles;
	for (int i = 0; i < total; i++) {
		vector<int> line(3);
		cin >> line[0] >> line[1] >> line[2];
		circles.push_back(line);
	}

	cout << countLatticePoints(circles) << endl;
	return 0;
}

// https://leetcode.cn/problems/count-lattice-points-inside-a-circle/description/		ÄÑ¶È·Ö£º1603
// tag: #math #geometry #enum #doublepointer #arraydiff #notcompleted