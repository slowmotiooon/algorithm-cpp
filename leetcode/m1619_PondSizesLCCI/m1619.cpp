#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> land;

    for (int i = 0; i < m; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            int b;
            cin >> b;
            line.push_back(b);
        }
        land.push_back(line);
    }

    vector<int> result = pondSizes(land);
    for (int x : result) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/pond-sizes-lcci/
