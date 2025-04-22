#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k, sources, destinations;
    cin >> n >> k;

    vector<vector<int>> edges(k, vector<int>(2, 0));
    for (auto& l : edges) cin >> l[0] >> l[1];

    cin >> sources >> destinations;

    cout << validPath(n, edges, sources, destinations) << endl;
    return 0;
}

// https://leetcode.cn/problems/find-if-path-exists-in-graph