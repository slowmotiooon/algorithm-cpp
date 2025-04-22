#pragma once

#include <vector>
using namespace std;

bool canMakeSquare(vector<vector<char>>& grid) {
	int s[2] = { 0,0 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			grid[i][j] == 'W' ? s[0]++ : s[1]++;
			grid[i+1][j] == 'W' ? s[0]++ : s[1]++;
			grid[i][j+1] == 'W' ? s[0]++ : s[1]++;
			grid[i+1][j+1] == 'W' ? s[0]++ : s[1]++;
			if (s[0] <= 1 || s[1] <= 1) return true;
			s[0] = 0;
			s[1] = 0;
		}
	}
	return false;
}

// Í¨¹ý | 0ms | 19.43MB
// O(1)? | O(1)