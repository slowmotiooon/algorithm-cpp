#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    vector<vector<int>> graph = { { 4, 3, 1 }, { 3, 2, 4 }, { 3 }, { 4 }, {} };
    vector<vector<int>> result = allPathsSourceTarget(graph);

    for (auto l : result) {
        for (int x : l) cout << x << ' ';
        cout << endl;
    }
    return 0;
}

// https://leetcode.cn/problems/all-paths-from-source-to-target 1383
