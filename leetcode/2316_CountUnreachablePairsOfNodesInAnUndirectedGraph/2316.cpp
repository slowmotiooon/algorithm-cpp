#include "solution3.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> edges;
    for (int i = 0; i < k; i++) {
        vector<int> line(2);
        cin >> line[0] >> line[1];
        edges.push_back(line);
    }
    cout << countPairs(n, edges) << endl;
    return 0;
}

// https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
// 1604