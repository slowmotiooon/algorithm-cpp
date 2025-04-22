#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	int rows, cols;
	cin >> rows >> cols;

	vector<vector<int>> matrix;

	for (int i = 0; i < rows; i++) {
		vector<int> line;
		for (int j = 0; j < cols; j++) {
			int buffer;
			cin >> buffer;
			line.push_back(buffer);
		}
		matrix.push_back(line);
	}

	int target;
	cin >> target;

	cout << searchMatrix(matrix, target) << endl;
	//vector<int> result = searchMatrixPlace(matrix, target);
	//cout << result[0] << " " << result[1] << endl;
	return 0;
}