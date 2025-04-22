#include "solution2.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> heights;
    for (int i = 0; i < m; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            int b;
            cin >> b;
            line.push_back(b);
        }
        heights.push_back(line);
    }

    vector<vector<int>> result = pacificAtlantic(heights);
    for (vector<int> x : result) cout << x[0] << ' ' << x[1] << ", ";
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/pacific-atlantic-water-flow/